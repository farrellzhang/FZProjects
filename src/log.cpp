#include"../include/log.h"
#include<string.h>
#include<time.h>
//日志类实现
Log* Log::_log = 0;
Log::Log()
{
    init();
}
Log::~Log()
{
    stream();
    if (_file)
    {
	fclose(_file);
	_file = 0;
    }
}
Log* Log::instance()
{
    if (!_log)
	_log = new Log();
    return _log;
}
void Log::free_instance()
{
    if (_log)
    {
	delete _log;
	_log = 0;
    }
}
void gettime(char timestr[64])
{
    time_t t;
    tm* local;
    bzero(timestr, sizeof(timestr));
    time(&t);
    local = localtime(&t);
    sprintf(timestr, "%02d%02d %02d:%02d:%02d ", local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
}
void Log::init()
{
    time_t t;
    tm* local;
    char name[64];
    time(&t);
    local = localtime(&t);
    sprintf(name, "%04d%02d%02d%02d%02d%02d.log", local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
    _file = fopen(name, "wt");
    if (!_file)
    {
	printf("fopen error!\n");
    }
}
void Log::write(const char* content)
{
    if (_file && content)
    {
	char time[64];
	gettime(time);
	fwrite(time, sizeof(time), 1, _file);
	fwrite(content, sizeof(content), 1, _file);
    }
}
std::ostringstream& Log::stream()
{
    //将当前日志写入文件后清空
    std::string str = _stream.str();
    if (!str.empty())
    {
       str += "\n";
    }
    if (_file)
    {
	char time[64];
	gettime(time);
	fwrite(time, sizeof(time), 1, _file);
	fwrite(str.c_str(), str.size(), 1, _file);
	fflush(_file);
    }

    _stream.str("");
    return _stream;
}
