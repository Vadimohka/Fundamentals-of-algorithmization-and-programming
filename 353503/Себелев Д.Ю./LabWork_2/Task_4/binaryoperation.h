#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

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

#endif // BINARYEXPRESSION_H
