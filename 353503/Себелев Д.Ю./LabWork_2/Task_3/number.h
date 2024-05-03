#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    Number();
    Number(double value);

    double evaluate() override;

private:
    double m_value;
};

#endif // NUMBER_H
