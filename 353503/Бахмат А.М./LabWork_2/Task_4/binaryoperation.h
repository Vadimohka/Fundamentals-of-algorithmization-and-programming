#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression*, char, Expression*);
    ~BinaryOperation();
    void calculate(double, char, double);
    double evaluate() override;
private:
    Expression* _expression1;
    Expression* _expression2;
    double _number;
};

#endif // BINARYOPERATION_H
