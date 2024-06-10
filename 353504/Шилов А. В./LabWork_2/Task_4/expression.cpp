#include "expression.h"

Number::Number(double num)
    : Expression(), value(num)
{}


double Number::Evaluate()
{
    return value;
}


BinaryOperation::BinaryOperation(Expression* left, char action, Expression* right)
    : action(action), left(left), right(right)
    {};

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}


double BinaryOperation::Evaluate()
{
    switch (action)
    {
    case '+': return(left->Evaluate() + right->Evaluate());
    case '-': return(left->Evaluate() - right->Evaluate());
    case '*': return(left->Evaluate() * right->Evaluate());
    case '/': return(left->Evaluate() / right->Evaluate());
    default: return(0);
    }
};
