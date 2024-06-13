#include "binaryoperation.h"

#include "stdexcept"

BinaryOperation::BinaryOperation(Expression *left, char operation, Expression *right) : leftOperand(left), op(operation), rightOperand(right) {}

double BinaryOperation::evaluate() const
{
    double leftValue = leftOperand->evaluate();
    double rightValue = rightOperand->evaluate();

    switch (op) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        throw std::runtime_error("Invalid operator");
    }
}

BinaryOperation::~BinaryOperation()
{
    delete leftOperand;
    delete rightOperand;
}

