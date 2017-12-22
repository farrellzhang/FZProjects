#include"../include/log.h"
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
void Log::init()
{
    time_t t;
    tm* local;
    char name[64];
    t = time(0);
    local = localtime(&t);
    sprintf(name, "%d%d%d%d%d%d.log", local->tm_year, local->tm_mon, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);
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
	printf(content);
	fwrite(content, sizeof(content), 1, _file);
	fwrite("zhangfang", 9, 1, _file);
    }
}
std::ostringstream& Log::stream()
{
    //将当前日志写入文件后清空
    std::string str = _stream.str();
    write(str.c_str());
    _stream.clear();
    return _stream;
}
