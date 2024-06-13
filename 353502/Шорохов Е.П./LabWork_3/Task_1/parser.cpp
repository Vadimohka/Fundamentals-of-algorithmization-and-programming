#include "parser.h"
//I am booored
const uint8_t BITS = 8;
const uint8_t ONE = 1;

Parser::Parser() = default;

QString Parser::ReadFromPtr(uint8_t* ptr, size_t remains)
{
    if (remains == 0)
    {
        return "";
    }

    return ReadFromByte(ptr) + ReadFromPtr(ptr+1, remains-1);
}

QString Parser::ReadFromByte(uint8_t* ptr, size_t from)
{
    if (from == BITS)
    {
        return "";
    }

    return ReadFromByte(ptr, from + 1) + QString::number((*ptr>>from)&ONE);
}

QString Parser::DtoS(double value)
{
    return ReadFromPtr(reinterpret_cast<uint8_t*>(&value), sizeof(double));
}
