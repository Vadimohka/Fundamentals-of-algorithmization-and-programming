#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : Expression
{
private:
    Expression* expr1;
    Expression* expr2;
    char operation;

public:
    BinaryOperation(Expression *expr1, const char operation, Expression *expr2);
    ~BinaryOperation() override = default;

    double evaluate() override;
};

#endif // BINARYOPERATION_H
