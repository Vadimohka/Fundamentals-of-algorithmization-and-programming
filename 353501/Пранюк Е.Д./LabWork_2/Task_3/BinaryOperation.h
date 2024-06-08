//
// Created by Daniil Mariyn on 10.03.24.
//

#ifndef SEM_2_LAB_2_3_BINARYOPERATION_H
#define SEM_2_LAB_2_3_BINARYOPERATION_H

#include "Expression.h"
#include "Number.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression*,char,Expression*);
    ~BinaryOperation();
    double evaluate() override;
private:
    Expression *left;
    Expression *right;
    char op;
};


#endif//SEM_2_LAB_2_3_BINARYOPERATION_H
