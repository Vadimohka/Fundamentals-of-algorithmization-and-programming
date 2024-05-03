#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#pragma once
#include <iostream>
#include <Expression.h>

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* left, char operation, Expression* right) : left(left), right(right), operation(operation) {}
    ~BinaryOperation() {delete left; delete right;}
    double Evaluate() const override
    {
        double lValue = left->Evaluate();
        double rValue = right->Evaluate();

        switch (operation)
        {
        case '+':
            return lValue + rValue;
        case '-':
            return lValue - rValue;
        case '*':
            return lValue * rValue;
        case '/':
            if (rValue)
                return lValue / rValue;
            else
                throw std::invalid_argument("Division by zero");
        default:
            throw std::invalid_argument("Invalid operation argument");
        }
    }
private:
    Expression* left;
    Expression* right;
    char operation;
};

#endif // BINARYOPERATION_H
