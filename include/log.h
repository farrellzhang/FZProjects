#include<stdio.h>
#include<stdlib.h>
#include<iosfwd>
#include<sstream>
//日志接口
class Log
{
    public:
	static Log* instance();
	static void free_instance();
	void write(const char* content);
	std::ostringstream& stream();
    private:
	Log();
	~Log();
	void init();
    private:
	static Log* _log;
	FILE* _file;
	std::ostringstream _stream;
};

#define LOG Log::instance()->stream()
