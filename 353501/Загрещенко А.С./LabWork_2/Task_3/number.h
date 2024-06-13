#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
private:
    double value;

public:
    Number(double val);
    double evaluate() const override;
};

#endif // NUMBER_H
