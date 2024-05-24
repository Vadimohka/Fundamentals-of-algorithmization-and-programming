//
// Created by darina on 4/6/24.
//

#include "BinaryOperation.h"

double BinaryOperation::evaluate() {
    switch (operation) {
        case '+':
        {
            return left->evaluate() + right->evaluate();
        }
        case '*':
        {
            return left->evaluate() * right->evaluate();
        }
        case '-':
        {
            return left->evaluate() - right->evaluate();
        }
        default:
        {
            if(right->evaluate() == 0)
            {
                throw "dividing by zero";
            }
            return left->evaluate() / right->evaluate();
        }
    }
}

BinaryOperation::BinaryOperation(Expression* left, char operation, Expression* right) {
    this->operation = operation;
    this->left = left;
    this->right = right;
}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;

}
