#pragma once
#include "Expression.h"

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char op, Expression* right)
        : left(left), right(right), op(op) {}
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }
    double evaluate() const
    {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        switch (op)
        {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
        default: return 0.0; // invalid operation
        }
    }
private:
    Expression* left;
    Expression* right;
    char op;
};
