//
// Created by Марат Гасанов on 31.10.2022.
//

#include "excel_format.h"
#include "iostream"
#include <stdexcept>

char toChar(int i){
    switch (i) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            break;
    }
}


std::string ExcelFormat::format(int num) {
    std::string format_string;
    if (num > 0){
        format_string = pos_int_;
    }
    else if(num < 0){
        format_string = neg_int_;
    }
    std::string output_str;
    for (int i = format_string.size()-1;i >= 0 ;i--){
        int res = num % 10;
        char symbol = format_string[i];
        switch (symbol) {
            case '#':
                if (num != 0)output_str.insert(0, 1, toChar(res));
                num /= 10;
                break;
            case '0':
                if (num != 0)output_str.insert(0, 1, toChar(res));
                else output_str.insert(0, 1, '0');
                num /= 10;
                break;
            case '?':
                if (num != 0)output_str.insert(0, 1, toChar(res));
                else output_str.insert(0, 1, ' ');
                num /= 10;
                break;
            default:
                output_str.insert(0, 1, symbol);
                break;
        }
    }
    return output_str;
}

std::string ExcelFormat::format(std::string string) {
    std::string output_str;
    for (char symbol : string_str_){
        if (symbol == '@') output_str.append(string);
        else output_str += symbol;
    }
    return output_str;
}

ExcelFormat::ExcelFormat(std::string format_str) {
    size_t pos = 0;
    std::string token;
    size_t i = 0;
    while ( (pos = format_str.find(';')) != std::string::npos){
        token = format_str.substr(0, pos);
        format_str.erase(0, pos + 1);
        switch (i) {
            case 0:
                pos_int_ = token;
                break;
            case 1:
                neg_int_ = token;
                break;
            case 2:
                zero_str_ = token;
            default:
                break;
        }
        i++;
    }
    if (i == 3) {
        string_str_ = format_str;
    }
    else{
        throw std::invalid_argument("expected format pos;neg;zero;str");
    }
    proccesingIntFormat();
}

void ExcelFormat::proccesingIntFormat() {
    bool isZero = false;
    for(int i = 0; i < pos_int_.size(); i++){
        char symbol = pos_int_[i];
        if (symbol == '0') isZero = true;
        if (isZero && (symbol == '?' || symbol == '0' || symbol == '#')){
            pos_int_[i] = '0';
        }
    }

    isZero = false;
    for(int i = 0; i < neg_int_.size(); i++){
        char symbol = neg_int_[i];
        if (symbol == '0') isZero = true;
        if (isZero && (symbol == '?' || symbol == '0' || symbol == '#')){
            neg_int_[i] = '0';
        }
    }
}
