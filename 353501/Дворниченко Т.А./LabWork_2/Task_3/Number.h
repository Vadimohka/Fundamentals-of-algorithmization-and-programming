#pragma once
#include "Expression.h"

class Number : public Expression
{
public:
    Number(double value) : value(value) {}
    double evaluate() const { return value; }
private:
    double value;
};
