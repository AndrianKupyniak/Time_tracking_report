#include "Date.h"
#include "Logger/Logger.h"

void Date::validate_date(){
    if(m_month > 12 || m_month <= 0){
        m_month = 1;
        LOG_ERROR("invalid month changed");
    }
    if(m_year > 2022 || m_year <= 1900){
        m_year = 1900;
        LOG_ERROR("invalid year changed");
    }
}  

std::string Date::month_to_string()const{
    switch(m_month){
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "None";
    }
}        

Date::Date(const std::string& YYYY_MM_DD){
    if(YYYY_MM_DD.size() == 10){
        m_year = stoi(YYYY_MM_DD.substr(0, 4));
        m_month = stoi(YYYY_MM_DD.substr(5, 7));
    }else{
        LOG_ERROR("invalid date fromat");
        m_year  = 1900;
        m_month = 1;
    }
    validate_date();
}

std::string Date::to_str()const{
    return month_to_string() + " " + std::to_string(m_year);
}

bool operator<(const Date& l, const Date& r){
    if(l.m_year < r.m_year){
        return true;
    }else if (l.m_year == r.m_year) {
        if(l.m_month < r.m_month){
            return true;
        }
    }
    return false;
}