#include <iostream>
#ifndef LOGGER_H
#define LOGGER_H
using namespace std;

class Logger
{
    public:
        void log(string wartosc);
        bool bool_debug;
        Logger(bool debug = true);
};

#endif