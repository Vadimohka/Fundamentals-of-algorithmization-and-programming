#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *_left, char _operation, Expression *_right)
    : left(_left)
    , right(_right)
    , operation(_operation)
{}

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}

double BinaryOperation::evaluate()
{
    if (operation == '+') {
        return left->evaluate() + right->evaluate();
    } else if (operation == '-') {
        return left->evaluate() - right->evaluate();
    } else if (operation == '/') {
        return left->evaluate() / right->evaluate();
    } else if (operation == '*') {
        return left->evaluate() * right->evaluate();
    } else {
        throw;
    }
}
