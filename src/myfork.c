#include<unistd.h>
#include<stdio.h>
int main()
{
    pid_t fpid;
    int count = 0;
    printf("before fork\n");
    fpid = fork();
    if (fpid < 0)
    {
	printf("fork error!\n");
    }
    else if (fpid == 0)
    {
	printf("i am the child process, process id: %d\n", getpid());
    }
    else 
    {
	printf("i am the origin process, process id: %d\n", getpid());
	printf("wait child exit\n");
	waitpid(fpid, 0, 0);
	printf("child exit!\n");
    }
    printf("procee: %d, eixt\n", getpid());
    return 0;
}
