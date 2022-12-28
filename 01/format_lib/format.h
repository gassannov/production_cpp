//
// Created by Марат Гасанов on 31.10.2022.
//

#ifndef INC_01_FORMAT_H
#define INC_01_FORMAT_H
#include "string"

class Format{
public:
    virtual std::string format(int num) = 0;
    virtual std::string format(std::string) = 0;
};

#endif //INC_01_FORMAT_H
