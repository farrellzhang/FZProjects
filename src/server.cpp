#include<errno.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include"../include/server.h"
#include"../include/log.h"

FileServer::FileServer()
{
    //   _sk = 0;
    //   _efd = 0;
    //   _tid = 0;
}

FileServer::~FileServer()
{

}
void FileServer::start()
{
    int listenfd, connfd, efd, nfds, i, readlen;
    epoll_event ev, events[128];
    char buf[1024]={0};
    char* result = 0;
    FILE* file = 0;
    sockaddr_in saddr, caddr;
    const int addrlen = sizeof(sockaddr);
    //本机地址
    bzero(&saddr, sizeof(saddr));
    bzero(&caddr, sizeof(caddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(7778);
    saddr.sin_addr.s_addr = INADDR_ANY;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > listenfd)
    {
	LOG << "create socket fail: " << errno;
	return;
    }
    LOG << "socket create: " << listenfd;
    i = 1;
    if (0 > setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int)))
    {
	LOG << "setsockopt fail: " << errno;
    }
    if (0 > bind(listenfd, (sockaddr*)&saddr, sizeof(saddr)))
    {
	LOG << "bind socket fail: " << errno;
	return;
    }
    LOG << "bind";
    efd = epoll_create(128);
    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;
    if (0 > epoll_ctl(efd, EPOLL_CTL_ADD, listenfd, &ev))
    {
	LOG << "epoll_ctl fail: " << errno;
	return;
    }
    LOG << "epoll_ctl";
    if (0 > listen(listenfd, 12))
    {
	LOG << "listen fail: " << errno;
	return;
    }
    LOG << "listen";
    while(1)
    {
	//LOG << "epoll_wait";
	nfds = epoll_wait(efd, events, 12, -1);
	if (nfds < 0)
	{
	    if (errno == EINTR)
		continue;
	    LOG << "epoll_wait fail: " << errno;
	}
	for (i = 0; i < nfds; ++i)
	{
	    if (events[i].data.fd == listenfd)
	    {
		//等待连接
		connfd = accept(listenfd, (sockaddr*)&caddr,
			(socklen_t*)&addrlen);
		if (connfd > 0)
		{
		    LOG << "new connect socket: " << connfd;
		    //设置为异步
		    fcntl(connfd, F_SETFL,
			    fcntl(connfd, F_GETFL)|O_NONBLOCK);
		    //加入等待队列
		    ev.data.fd = connfd;
		    ev.events = EPOLLIN | EPOLLET;
		    if (0 > epoll_ctl(efd, EPOLL_CTL_ADD, connfd, &ev))
		    {
			LOG << "epoll_ctl fd: " << connfd 
			    << ", fail: " << errno;
			return;
		    }
		}
	    }
	    else
	    {
		while (1)
		{
		    //有数据到来
		    bzero(buf, sizeof(buf));
		    readlen = read(events[i].data.fd, buf, sizeof(buf));
		    if (readlen > 0)
		    {
			if (file)
			{
			    //直接写数据
			    fwrite(buf, readlen, 1, file);
			}
			else
			{
			    //解析数据,以#为分割，依次为文件名、文件大小
			    result = strtok(buf, "#");
			    if (result)
			    {
				LOG << "file: " << result;
				file = fopen(result, "wb");
				if (file)
				{
				    result = strtok(0, "#");
				    if (result)
				    {
					LOG << "filesize: " << result;
				    }
				}	
			    }
			}
		    }
		    else
		    {
			if (readlen == -1 && errno == EAGAIN)
			{
			    continue;
			}
			else if (readlen == 0)
			{
			    //关闭文件
			    if (file)
			    {
				fclose(file);
				file = 0;
				LOG << "file data recv over!";
			    }
			    //停止监视
			    epoll_ctl(efd, EPOLL_CTL_DEL, events[i].data.fd, &ev);
			    close(events[i].data.fd);
			    break;
			}
		    }
		}
	    }
	}
    }
}

int main()
{
    LOG << "start";
    FileServer fs;
    fs.start();
    // Log::free_instance();
    return 0;
}
