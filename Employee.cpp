#include "Employee.h"        
#include "Logger/Logger.h"
        
        Employee::Employee(const std::string& name, const Date date, const uint& loggedHours): 
                m_name(name), m_date(date), m_loggedHours(loggedHours){
                    add_log(date, m_loggedHours);
        }
        void Employee::add_log(const Date date, const uint hours){
            m_loggedHours += hours;
            if (m_logs.find(date) != m_logs.end()){
                m_logs.at(date) += hours;
            } else {
                m_logs[date] = hours;
            }
            LOG_DEBUG("updated logged hours of employee");
        }

        std::ostream& operator<<(std::ostream& os, const Employee& c){
            for(const auto& elem: c.m_logs){
                os << c.m_name << " " << elem.first.to_str() << " " << elem.second << "\n";
            }
            return os;
        }
        std::string Employee::to_str(std::string delimiter)const{
            std::string result{};
            for(const auto& elem: m_logs){
                result += m_name + delimiter + elem.first.to_str() + delimiter + std::to_string(elem.second) + "\n";
            }
            return result;
        }