#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
private:
    char op;
    Expression* leftOperand;
    Expression* rightOperand;

public:
    BinaryOperation(Expression* left, char operation, Expression* right);


    double evaluate() const override;

    ~BinaryOperation();
};

#endif // BINARYOPERATION_H
