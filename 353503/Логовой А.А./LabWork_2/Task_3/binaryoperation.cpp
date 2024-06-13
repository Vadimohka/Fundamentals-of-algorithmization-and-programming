#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* left, char operation, Expression* right) {
    this->left = left;
    this->right = right;
    this->operation = operation;
}

double BinaryOperation::evaluate() const {

    switch(operation){
    case '+':
        return left->evaluate() + right->evaluate();

    case '-':
        return left->evaluate() - right->evaluate();

    case '*':
        return left->evaluate() * right->evaluate();

    case '/':
        if (right->evaluate() != 0)
            return left->evaluate() / right->evaluate();
         else
            throw std::invalid_argument("Division by zero");

    default:
        throw std::invalid_argument("Not find operation");
    }
}


BinaryOperation::~BinaryOperation(){
    delete left;
    delete right;
}
