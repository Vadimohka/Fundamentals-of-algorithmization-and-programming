#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number();
    Number(double);
    double evaluate() override;
private:
    double number;
};

#endif // NUMBER_H
