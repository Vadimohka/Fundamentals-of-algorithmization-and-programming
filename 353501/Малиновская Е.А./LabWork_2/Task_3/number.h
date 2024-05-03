#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number(double value);
    ~Number();

    double evaluate() const override;

private:
    double m_value;
};

#endif // NUMBER_H
