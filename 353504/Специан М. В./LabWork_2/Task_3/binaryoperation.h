#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression {
public:
    BinaryOperation();
    ~BinaryOperation();

    BinaryOperation(Expression *left, char op, Expression *right);
    double evaluate() const;

    // for task 4
    bool isBinaryOperation() const { return true; }

private:
    Expression *left;
    Expression *right;
    char op;
};

#endif // BINARYOPERATION_H
