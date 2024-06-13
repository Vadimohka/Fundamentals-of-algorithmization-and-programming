#ifndef NUMBER_H
#define NUMBER_H
#include "expression.h"

class Number : public Expression
{
public:
    Number();
    virtual ~Number();
    Number(double value);
    double value_;
    double evaluate() override;
};

#endif // NUMBER_H
