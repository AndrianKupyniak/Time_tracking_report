#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>

#include <map>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "Timer.h"
#include "Logger/Logger.h"


class Parser{
    private:            
        std::map<std::string, Employee> m_employees;
        std::string m_filename;
        std::string m_delimiter = ";";
        Timer m_timer;

        void get_data_from_file();
    public:
        Parser(){};
        Parser(const std::string& filename, const std::string& delimiter = ";"): 
            m_filename(filename), m_delimiter(delimiter){}
        Parser(const Parser& r): 
            Parser{r.m_filename, r.m_delimiter}{}
            
        void parse(); 
        std::map<std::string, Employee> get_data()const;
        void save_to_file(std::string& out_filename);
};

#endif