#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression {
private:
    Expression *left;
    Expression *right;
    char type;
public:
    BinaryOperation(Expression *left, char type, Expression *right);
    ~BinaryOperation();

    double evaluate() override;
};

#endif // BINARYOPERATION_H
