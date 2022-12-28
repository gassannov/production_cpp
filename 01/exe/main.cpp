//
// Created by Марат Гасанов on 31.10.2022.
//
#include <vector>
#include "iostream"
#include "../format_lib/excel_format.h"

int main(int argc, char** argv){
    if (argc != 3){
        return 1;
    }

    std::string format_str = std::string(argv[1]);
    ExcelFormat ex_format = ExcelFormat(format_str);
    std::string str_to_format = std::string(argv[2]);

    char* p;
    long converted = strtol(str_to_format.c_str(), &p, 10);

    if (*p) {
        std::string a = ex_format.format(std::string(p));
        std::cout << "formatted_a: " <<  a << std::endl;
    }
    else{
        std::string a = ex_format.format(int(converted));
        std::cout << "formatted_a: " <<  a << std::endl;
    }
}