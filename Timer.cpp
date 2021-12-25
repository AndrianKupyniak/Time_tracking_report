#include "Timer.h"

void Timer::start(){
    m_start_time = std::chrono::high_resolution_clock::now();
};

void Timer::stop(){
    m_end_time = std::chrono::high_resolution_clock::now();
};

void Timer::reset(){
    m_start_time = m_end_time = {};
};

long Timer::get_time()const{
    return std::chrono::duration_cast<std::chrono::microseconds>(m_end_time - m_start_time).count();
}