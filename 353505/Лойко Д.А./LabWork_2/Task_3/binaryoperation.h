#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H
#include "expression.h"
#include <QDebug>

class BinaryOperation : public Expression {
public:
    BinaryOperation(Expression *newLeft, char type, Expression *newRight);
    ~BinaryOperation();

    double evaluate() override;
private:
    Expression *left;
    Expression *right;
    char type;
};
#endif // BINARYOPERATION_H
