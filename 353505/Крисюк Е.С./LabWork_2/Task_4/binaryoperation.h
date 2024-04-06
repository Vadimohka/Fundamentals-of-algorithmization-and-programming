#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation();
    ~BinaryOperation();

    BinaryOperation(Expression*, char, Expression*);
    double evaluate() override;
private:
    Expression* operand_left;
    Expression* operand_right;
    char operation;
};

#endif // BINARYOPERATION_H
