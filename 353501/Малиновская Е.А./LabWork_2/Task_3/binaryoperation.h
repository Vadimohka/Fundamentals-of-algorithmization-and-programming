#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* leftOperand, char operation, Expression* rightOperand);
    ~BinaryOperation();

    double evaluate() const override;

private:
    Expression* m_leftOperand;
    Expression* m_rightOperand;
    char m_operation;
};

#endif // BINARYOPERATION_H
