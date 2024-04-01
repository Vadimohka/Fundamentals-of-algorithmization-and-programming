#ifndef NUMBER_H
#define NUMBER_H

#include "Expression.h"

class Number : public Expression
{
public:
    Number(double x);
    double evaluate();
private:
    double number;
};

#endif // NUMBER_H
