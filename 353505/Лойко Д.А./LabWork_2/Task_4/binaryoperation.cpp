#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *newLeft, char newType, Expression *newRight) {
    left = newLeft;
    right = newRight;
    type = newType;
}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}

double BinaryOperation::evaluate() {
    switch (type) {
    case '+':
        return (left->evaluate() + right->evaluate());
    case '-':
        return (left->evaluate() - right->evaluate());
    case '*':
        return (left->evaluate() * right->evaluate());
    case '/':
        if (right->evaluate() != 0) {
            return (left->evaluate() / right->evaluate());
                }
        else {
            qDebug() << "Error\n";
        }
        break;
    default:
        qDebug() << "What u fucking doing\n";
        break;
    }
    return 0;
}
