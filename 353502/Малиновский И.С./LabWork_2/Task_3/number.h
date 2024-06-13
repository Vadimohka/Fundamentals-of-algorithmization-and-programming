#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression {
public:
    explicit Number(double value) : value(value) {}
    virtual double evaluate() const override {
        return value;
    }
private:
    double value;
};

#endif // NUMBER_H
