#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED


#include <iostream>
#include <string>
#include <map>
#include "Date.h"
#include "Logger/Logger.h"

class Employee{
    private:
        std::string m_name;
        Date m_date;
        uint16_t m_loggedHours;
        std::map<Date, uint16_t> m_logs;
    public:
        Employee(const std::string& name, const Date date, const uint16_t& loggedHours);

        void add_log(const Date date, const uint16_t hours);
        friend std::ostream& operator<<(std::ostream& os, const Employee& c);
        std::string to_str(std::string delimiter)const;
};

#endif