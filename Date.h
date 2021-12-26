#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include "Logger/Logger.h"

class Date{
    private:
        void validate_date();
        std::string month_to_string()const;
        uint16_t m_year = 0;
        uint16_t m_month = 0;
    public: 
        Date(const std::string& YYYY_MM_DD);

        std::string to_str()const;
        friend bool operator<(const Date& l, const Date& r);
};

#endif