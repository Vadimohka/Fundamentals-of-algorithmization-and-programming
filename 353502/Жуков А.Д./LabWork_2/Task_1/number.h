#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : Expression
{
private:
    double number;

public:
    explicit Number(const double num);
    ~Number() override = default;

    double evaluate() override;
};

#endif // NUMBER_H
