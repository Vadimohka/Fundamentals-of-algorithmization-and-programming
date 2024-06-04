#ifndef TASK3_NUMBER_H
#define TASK3_NUMBER_H

#include "Expression.h"

class Number : public Expression{
public:
    explicit Number(double x);
    double evaluate() override;

private:
    double value;
};


#endif //TASK3_NUMBER_H
