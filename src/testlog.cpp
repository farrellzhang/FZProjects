#include "../include/log.h"
int main()
{
    LOG << "hello test log!";
    Log::free_instance();
    return 0;
}
