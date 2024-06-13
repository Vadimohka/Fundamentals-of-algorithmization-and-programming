//
// Created by acryoz on 28.2.24.
//

#ifndef UNTITLED5_DATEEXCEPTION_H
#define UNTITLED5_DATEEXCEPTION_H
#include <exception>
#include <string>


class DateException: public std::exception{
public:
    DateException(const std::string&);
    const char* what();
private:
    std::string message;
};


#endif //UNTITLED5_DATEEXCEPTION_H
