#include "Parser.h"
#include "Logger/Logger.h"

namespace{
    std::vector<std::string> split_string(std::string& str, const std::string& delimiter){
        std::vector<std::string> result;
        
        while(str.size()){
            size_t index = str.find(delimiter);
            if(index != std::string::npos){
                result.push_back(str.substr(0, index));
                str = str.substr(index + delimiter.size());
                if(str.size() == 0){
                    result.push_back(str);
                }
            }else{
                result.push_back(str);
                str = "";
            }
        }
        return result;
    }
}

void Parser::get_data_from_file(){
    std::ifstream file(m_filename);
    std::string str; 

    while(std::getline(file, str)){
        auto vec = split_string(str, m_delimiter);
        if(vec.size() != 8){          
            LOG_ERROR("couldnt get data from line");
            continue;
        }
        std::string name(vec[0]), date(vec[6]), hours(vec[7]);
        
        if(m_employees.find(name) != m_employees.end()){
            LOG_DEBUG("added Log_hours to employee");
            m_employees.at(name).add_log(date, std::stoi(hours));
        }else{
            LOG_DEBUG("inserted new employee");
            m_employees.insert({name, Employee(name, date, std::stoi(hours))});
        }
    }            
}      

void Parser::parse(){
    LOG_VERBOSE("Started parsing");
    m_timer.start();
    get_data_from_file();
    m_timer.stop();
    LOG_VERBOSE("Ended parsing");
    std::cout << "Parsed in " << m_timer.get_time() << " microseconds" << "\n";
}

std::map<std::string, Employee> Parser::get_data()const{
    return m_employees;
}

void Parser::save_to_file(std::string& out_filename){
    std::ofstream file(out_filename);
    for(const auto& elem : m_employees){
        file << elem.second.to_str(m_delimiter);
    }
    LOG_DEBUG("Saved to file data");
    file.close();
}