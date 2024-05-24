#include "binaryoperation.h"

BinaryOperation::BinaryOperation() {}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}

BinaryOperation::BinaryOperation(Expression *left, char op, Expression *right)
    : left(left), op(op), right(right) {}

double BinaryOperation::evaluate() const {
    switch(op) {
    case '+':
        return left->evaluate() + right->evaluate();
    case '-':
        return left->evaluate() - right->evaluate();
    case '*':
        return left->evaluate() * right->evaluate();
    case '/':
        return left->evaluate()  / right->evaluate();
    default:
        return 0;
    }
}
