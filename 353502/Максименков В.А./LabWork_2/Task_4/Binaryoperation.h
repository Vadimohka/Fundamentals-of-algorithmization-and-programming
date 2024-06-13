#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "Expression.h"

class BinaryOperation : public Expression
{
private:
    Expression* left;
    Expression* right;
    char simbol;

public:
    BinaryOperation(Expression* leftValue, char opSimbol, Expression *rightValue) : left(leftValue), right(rightValue), simbol(opSimbol) {}

    ~BinaryOperation() override
    {
        delete left;
        delete right;
    }

    double evaluate() override
    {
        switch (simbol)
        {
            case '+':
                return left->evaluate() + right->evaluate();
                break;
            case '-':
                return left->evaluate() - right->evaluate();
                break;
            case '*':
                return left->evaluate() * right->evaluate();
                break;
            case '/':
                return left->evaluate() / right->evaluate();
                break;
            default:
                return 0.0;
                break;
        };
    }
};

#endif  // BINARYOPERATION_H
