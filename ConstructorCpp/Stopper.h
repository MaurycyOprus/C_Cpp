#include <iostream>
#ifndef STOPPER_H
#define STOPPER_H
using namespace std;

class Stopper
{
    public:
        time_t obecny = 0;
        time_t start_;
        time_t stop_;

        void start();
        void stop();
        void reset();
        void print_czas();
};

#endif