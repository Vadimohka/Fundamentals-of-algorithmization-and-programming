#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"
#include "iostream"

class BinaryOperation : public Expression
{
private:
    Expression *left;
    Expression *right;
    char operation;

public:
    BinaryOperation(Expression *left, char operation, Expression *right)
        : left(left)
        , right(right)
        , operation(operation)
    {}
    double evaluate() override
    {
        switch (operation) {
        case '+':
            return (left->evaluate() + right->evaluate());
        case '-':
            return (left->evaluate() - right->evaluate());
        case '*':
            return (left->evaluate() * right->evaluate());
        case '/':
            if (right->evaluate() != 0) {
                return (left->evaluate() / right->evaluate());
            } else {
                std::cout << "Error\n";
            }
            break;
        default:
            std::cout << "Are you stupid?";
        }
        return 0.0;
    }
};

#endif // BINARYOPERATION_H
