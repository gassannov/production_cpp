//
// Created by Марат Гасанов on 31.10.2022.
//
#include "iostream"
#include "excel_format.h"

int main(){
    ExcelFormat ll = ExcelFormat("###;minus###;zero;str-@");
    std::string a = ll.format(256);
    std::string b = ll.format("string");
    std::string c = ll.format(-256);
    std::string d = ll.format(0);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}