#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number(double num);

    double evaluate() override;

    double getNumber();

private:
    double number;
};
#endif // NUMBER_H
