#ifndef NUMBER_H
#define NUMBER_H
#include "Expression.h"

class Number : public Expression
{
private:
    double num;

public:
    explicit Number(double value): num(value) {}

    double evaluate() override
    {
        return num;kyf
    }
};

#endif  // NUMBER_H
