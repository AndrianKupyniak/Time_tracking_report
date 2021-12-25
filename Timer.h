#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <iostream>
#include <chrono>
#include "Logger/Logger.h"

class Timer{
    private:
        std::chrono::high_resolution_clock::time_point m_start_time;
        std::chrono::high_resolution_clock::time_point m_end_time;
    public:
        Timer():m_start_time(){}

        void start();
        void stop();
        void reset();

        // returns time in microseconds
        long get_time()const;
};

#endif