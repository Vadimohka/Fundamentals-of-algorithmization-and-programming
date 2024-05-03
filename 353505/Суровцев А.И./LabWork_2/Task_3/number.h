#ifndef NUMBER_H
#define NUMBER_H
#include "expression.h"

class Number : public Expression
{
public:
    explicit Number(double number);
    double evaluate() const override;
private:
    double _number;
};

#endif // NUMBER_H
