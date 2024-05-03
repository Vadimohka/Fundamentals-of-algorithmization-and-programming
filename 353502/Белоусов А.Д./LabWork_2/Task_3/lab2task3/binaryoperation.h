#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
private:
    char type{'+'};
    Expression* left;
    Expression* right;
public:
    BinaryOperation();
    ~BinaryOperation() override;
    BinaryOperation(Expression* left, char type, Expression* right);
    double evaluate() override;
};

#endif // BINARYOPERATION_H
