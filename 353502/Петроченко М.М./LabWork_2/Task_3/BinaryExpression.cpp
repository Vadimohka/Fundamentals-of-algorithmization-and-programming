//
// Created by acryoz on 14.3.24.
//

#include "../headers/BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *l,  char op, Expression *r) {
    this->left = l;
    this->right = r;
    this->oper = op;
}


double BinaryExpression::evaluate() const {
    double result;
    double left_res = this->left->evaluate();
    double right_res = this->right->evaluate();
    switch (this->oper) {
        case op::Add:
            result = left_res + right_res;
            break;
        case op::Subtract:
            result = left_res - right_res;
            break;
        case op::Multiply:
            result = left_res * right_res;
            break;
        case op::Divide:
            if(right_res == 0){
                throw std::overflow_error("Divide by zero exception");
            }
            else{
                result = left_res / right_res;
            }
            break;
    }
    return result;
}


BinaryExpression::~BinaryExpression() {
    delete this->left;
    delete this->right;
}

