#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation();
    BinaryOperation(Expression *left, char operation, Expression *right);
    ~BinaryOperation();

    double evaluate() override;

private:
    Expression *m_left;
    Expression *m_right;
    char m_operation;
};

#endif // BINARYOPERATION_H
