#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    explicit Number(double);

    double evaluate() override;

private:
    double value;
};

#endif // NUMBER_H
