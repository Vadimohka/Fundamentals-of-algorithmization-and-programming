#pragma once

#include "expression.h"

class BinaryOperation : public Expression {

public:
    BinaryOperation(Expression *left, char operationType, Expression *right);
    
    double getValue() override;

    ~BinaryOperation() override;
    
private:
    Expression *left_ = nullptr;
    Expression *right_ = nullptr;
    char operationType_;

};