#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *left, char op, Expression *right)
{
    _left = left;
    _op = op;
    _right = right;
}

BinaryOperation::~BinaryOperation()
{
    delete _left;
    delete _right;
}

double BinaryOperation::evaluate() const
{
    double left_value = _left->evaluate();
    double right_value = _right->evaluate();
    switch (_op) {
    case '+': return left_value + right_value;
    case '-': return left_value - right_value;
    case '*': return left_value * right_value;
    case '/': return left_value / right_value;
    default:
        return 0.0;
    }
}
