#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
private:
    double number{0};
public:
    Number();
    explicit Number(double number);
    ~Number() override;
    void SetNumber(double number);
    double GetNumber();
    double evaluate() override;
};

#endif // NUMBER_H
