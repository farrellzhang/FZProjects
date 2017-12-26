#include "../include/log.h"
int main()
{
    LOG << "test log!";
    Log::free_instance();
    return 0;
}
