//
// Created by volodya-petarda on 5/11/24.
//

#ifndef LAB2_3_BINARYOPERATION_H
#define LAB2_3_BINARYOPERATION_H


#include "Expression.h"

class BinaryOperation : public Expression{
public:
    enum Operation
    {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE
    };

    BinaryOperation(Expression *left, Expression *right, Operation operation);
    double evaluate() override;

private:
    Operation operation;
    Expression *left, *right;
};


#endif //LAB2_3_BINARYOPERATION_H
