#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "Expression.h"

class BinaryOperation : public Expression {
private:
    char op;
    Expression *leftOperand;
    Expression *rightOperand;
public:
    BinaryOperation(Expression *left, char operation, Expression *right);
    virtual double evaluate() const override;
    virtual ~BinaryOperation();
};

#endif // BINARYOPERATION_H
