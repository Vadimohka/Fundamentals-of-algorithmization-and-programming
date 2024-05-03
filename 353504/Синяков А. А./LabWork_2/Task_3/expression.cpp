#include "expression.h"
#include <iostream>

Expression::Expression(QObject *parent) : QObject(parent) {}

Expression::~Expression() {}

Number::Number(double val, QObject *parent) : Expression(parent), value(val) {}

double Number::evaluate() const {
    return value;
}

Number::~Number() {}

BinaryOperation::BinaryOperation(Expression* left, char op, Expression* right, QObject *parent)
    : Expression(parent), leftOperand(left), rightOperand(right), operation(op) {}

double BinaryOperation::evaluate() const {
    double leftVal = leftOperand->evaluate();
    double rightVal = rightOperand->evaluate();

    switch(operation) {
    case '+':
        return leftVal + rightVal;
    case '-':
        return leftVal - rightVal;
    case '*':
        return leftVal * rightVal;
    case '/':
        if (rightVal == 0) {

            return 0; // Handling division by zero
        }
        return leftVal / rightVal;
    default:
        std::cout << "Error: Unknown operation\n";
        return 0;
    }
}

BinaryOperation::~BinaryOperation() {
    delete leftOperand;
    delete rightOperand;
}
