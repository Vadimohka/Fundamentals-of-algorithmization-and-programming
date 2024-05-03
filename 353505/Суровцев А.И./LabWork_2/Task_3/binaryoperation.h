#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char op, Expression* right);
    virtual ~BinaryOperation();
    double evaluate() const override;
private:
    Expression* _left;
    Expression* _right;
    char _op;
};

#endif // BINARYOPERATION_H
