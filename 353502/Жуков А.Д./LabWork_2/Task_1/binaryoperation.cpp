#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *expr1, const char operation, Expression *expr2)
    : expr1(expr1)
    , expr2(expr2)
    , operation(operation)
{}

double BinaryOperation::evaluate()
{
    switch(operation)
    {
    case '+':
        return expr1->evaluate() + expr2->evaluate();
    case '-':
        return expr1->evaluate() - expr2->evaluate();
    case '*':
        return expr1->evaluate() * expr2->evaluate();
    case '/':
        return expr1->evaluate() / expr2->evaluate();
    default:
        throw "Incorrect operation";
    }
}
