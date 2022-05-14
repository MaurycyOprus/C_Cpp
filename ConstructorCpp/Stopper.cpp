#include "Stopper.h"
#include <iostream>
#include <ctime>

void Stopper::start()
{
    start_ = time(0);
}

void Stopper::stop()
{
    stop_ = time(0);
    obecny = obecny + stop_ - start_;
}

void Stopper::reset()
{
    start_ = 0;
    stop_  = 0;
}

void Stopper::print_czas()
{
    cout<<obecny<<endl;
}