#include "BinaryOperation.h"
#include <stdexcept>
BinaryOperation::BinaryOperation(Expression *left, char operation, Expression *right) : op(operation), leftOperand(left), rightOperand(right) {}

double BinaryOperation::evaluate() const {
    double leftVal = leftOperand->evaluate();
    double rightVal = rightOperand->evaluate();
    switch(op) {    
        case '+':
            return leftVal + rightVal;
        case '-':
            return leftVal - rightVal;
        case '*':
            return leftVal * rightVal;
        case '/':
            if (rightVal != 0) {
                return leftVal / rightVal;
            } else {
                throw std::invalid_argument("Division by zero");
            }
        default:
            throw std::invalid_argument("Unknown operation");
    }
}

BinaryOperation::~BinaryOperation() {
    delete leftOperand;
    delete rightOperand;
}
