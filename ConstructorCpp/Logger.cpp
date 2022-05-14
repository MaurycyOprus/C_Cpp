#include "Logger.h"
#include <iostream>
#include <ctime>

void Logger::log(string wartosc)
{
    time_t czas = time(0);
    char* print = ctime(&czas);
    cout<<print<<endl;
    if (bool_debug != false)
    {
        cout<<wartosc<<endl;
    }
}

Logger::Logger(bool debug)
{
    bool_debug = debug;
}