#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
private:
    double num;

public:
    explicit Number(double number)
        : num(number)
    {}
    double evaluate() override { return num; }
};

#endif // NUMBER_H
