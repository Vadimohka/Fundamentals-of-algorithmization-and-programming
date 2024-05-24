//
// Created by darina on 4/6/24.
//

#ifndef TASK3_BINARYOPERATION_H
#define TASK3_BINARYOPERATION_H

#include "Expression.h"

class BinaryOperation : public Expression{
public:
    BinaryOperation(Expression* left, char operation, Expression* right);
    ~BinaryOperation();
    double evaluate() override;

private:
    Expression *left, *right;
    char operation;
};



#endif //TASK3_BINARYOPERATION_H
