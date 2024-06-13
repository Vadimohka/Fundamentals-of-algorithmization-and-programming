#ifndef PARSER_H
#define PARSER_H

//I am booored
#include <QString>

class Parser
{
public:
    Parser();
    static QString DtoS(double value);
    static QString ReadFromPtr(uint8_t* ptr, size_t remains);
    static QString ReadFromByte(uint8_t* ptr, size_t from = 0);
};

#endif // PARSER_H
