#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"
#include <number.h>
#include <stdexcept>

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char operation, Expression* right);
    ~BinaryOperation();

    double evaluate() const override;

private:
    Expression* left;
    Expression* right;
    char operation;
};

#endif // BINARYOPERATION_H
