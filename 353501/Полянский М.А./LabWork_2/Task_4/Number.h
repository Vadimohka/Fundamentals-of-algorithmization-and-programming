#ifndef NUMBER_H
#define NUMBER_H

#include "Expression.h"

class Number : public Expression {
private:
    double value;
public:
    Number(double val);
    virtual double evaluate() const override;
    virtual ~Number();
};

#endif // NUMBER_H
