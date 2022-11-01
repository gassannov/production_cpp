//
// Created by Марат Гасанов on 31.10.2022.
//

#ifndef INC_01_EXCELFORMAT_H
#define INC_01_EXCELFORMAT_H
#include "format.h"
#include "string"

class ExcelFormat : public Format{
private:
    std::string pos_int_;
    std::string pos_frac_;
    std::string neg_int_;
    std::string neg_frac_;
    std::string zero_str_;
    std::string string_str_;
public:
    ExcelFormat(std::string format_str);

    std::string format(int num) override;
    std::string format(std::string string) override;
    void proccesingIntFormat();
};

#endif //INC_01_EXCELFORMAT_H
