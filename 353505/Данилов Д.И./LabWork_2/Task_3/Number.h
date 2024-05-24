#ifndef NUMBER_H
#define NUMBER_H

#pragma once
#include <Expression.h>

class Number : public Expression
{
public:
    Number(double value) : value(value) {}
    double Evaluate() const override {return value;}
private:
    double value;
};

#endif // NUMBER_H
