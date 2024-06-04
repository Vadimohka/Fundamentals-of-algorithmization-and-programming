//
// Created by volodya-petarda on 5/11/24.
//

#include "BinaryOperation.h"

BinaryOperation::BinaryOperation(Expression *left, Expression *right, BinaryOperation::Operation operation) {
    this->left = left;
    this->right = right;
    this->operation = operation;
}

double BinaryOperation::evaluate() {
    double l = left->evaluate();
    double r = right->evaluate();

    switch(operation){
        case(PLUS):{
            return l + r;
            break;
        }
        case(MINUS):{
            return l - r;
            break;
        }
        case(MULTIPLY):{
            return l * r;
            break;
        }
        case(DIVIDE):{
            return l / r;
            break;
        }
    }
}
