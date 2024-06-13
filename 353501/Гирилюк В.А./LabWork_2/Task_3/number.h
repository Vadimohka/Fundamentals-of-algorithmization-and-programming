#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
    double value;
public:
    Number(double value);
    double evaluate() override;
};

#endif // NUMBER_H
