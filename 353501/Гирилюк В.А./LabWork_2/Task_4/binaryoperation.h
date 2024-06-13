#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"
#include "number.h"

class BinaryOperation : public Expression
{
    char operation;
    Expression* operand1, *operand2;

public:
    BinaryOperation(Expression* operand1, char operation, Expression* operand2);
    ~BinaryOperation();
    double evaluate() override;
};

#endif // BINARYOPERATION_H
