#include "binaryoperation.h"
#include <iostream>

BinaryOperation::BinaryOperation(Expression *left, char type, Expression *right) {
    this->left = left;
    this->right = right;
    this->type = type;
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
        } else {
            std::cout << "Error\n";
        }
        break;
    default:
        std::cout << "Wrong operator\n";
    }
    return 0;
}
