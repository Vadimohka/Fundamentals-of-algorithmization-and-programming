//
// Created by acryoz on 28.2.24.
//

#include "../headers/DateException.h"

DateException::DateException(const std::string& msg) {
    this->message = msg;
}

const char *DateException::what() {
    return this->message.c_str();
}