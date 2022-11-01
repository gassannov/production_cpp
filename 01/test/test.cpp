//
// Created by Марат Гасанов on 31.10.2022.
//

#include "excel_format.h"
#include <gtest/gtest.h>
#include "string"
#include "iostream"

TEST(test, TestPosFormat){
    std::string format_str = "0000;=0000;0;str:@";
    Format* excelFormat = new ExcelFormat(format_str);
    std::string pos = excelFormat->format(200);
    EXPECT_EQ(pos, "0200");
}

TEST(test, TestWrongFormatLine){
    try{
        Format* excelFormat = new ExcelFormat("##;-##;0");
    }
    catch(std::invalid_argument & err){
        std::cout << err.what() << "\n";
        std::string error_str = err.what();
        EXPECT_EQ(error_str, "expected format pos;neg;zero;str");
    }
}

TEST(test, TestStrFormat){
    std::string format_str = "0000;-0000;0;str:@";
    Format* excelFormat = new ExcelFormat(format_str);
    std::string neg = excelFormat->format("some");
    EXPECT_EQ(neg, "str:some");
}