#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "expression.h"


class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression*, char, Expression*);

    void Calc(double num_1, double num_2, char operation);

    double evaluate() override;

    ~BinaryOperation();

private:
    double number;
    Expression* num_1;
    Expression* num_2;
};

#endif // BINARYOPERATION_H
