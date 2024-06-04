#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression {
public:
    Number();
    Number(double);
    double evaluate() const;

    // for task 4
    bool isNumber() const { return true; }

private:
    double value;
};

#endif // NUMBER_H
