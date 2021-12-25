#include <iostream>
#include <string>

#include "Logger/Log.h"
#include "Parser.h"

int main(){
    SET_LOG_LEVEL(t_DEBUG);
    SET_LOGS_FILE("Logs.txt");
    SHOW_LOGS_IN_CONSOLE(true);

    std::string input_filename, input_delimeter, output_filename;
    
    std::cout << "\n";
    std::cout << "Input file name: ";
    std::cin >> input_filename;
    std::cout << "Data delimiter: ";
    std::cin >> input_delimeter;
    std::cout << "Output file name: ";
    std::cin >> output_filename;
    std::cout << "\n";
    
    try{
        Parser p(input_filename, input_delimeter);
        p.parse();
        p.save_to_file(output_filename);
    }catch(std::exception& e){
        LOG_FATAL(e.what());
    }
    return 0;
}