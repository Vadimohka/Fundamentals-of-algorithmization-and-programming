//
// Created by acryoz on 14.3.24.
//
#pragma once
#ifndef UNTITLED5_BINARYEXPRESSION_H
#define UNTITLED5_BINARYEXPRESSION_H


#include <iostream>
#include <stdexcept>
#include "Expression.h"


enum op {Add = '+', Subtract = '-', Multiply = '*', Divide = '/'};

class BinaryExpression: public Expression{
public:
    BinaryExpression(Expression*, char, Expression*);
    double evaluate() const override;
    ~BinaryExpression() override;
private:
    char oper;
    Expression* left;
    Expression* right;
};


#endif //UNTITLED5_BINARYEXPRESSION_H
