#include "binaryoperation.h"

BinaryOperation::BinaryOperation() = default;

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}

BinaryOperation::BinaryOperation(Expression *left, char type, Expression *right) : left(left), type(type), right(right)
{

}

double BinaryOperation::evaluate()
{
    if (type == '+')
    {
        return left->evaluate() + right->evaluate();
    }
    else if (type == '-')
    {
        return left->evaluate() - right->evaluate();
    }
    else if (type == '*')
    {
        return left->evaluate() * right->evaluate();
    }
    else if (type == '/')
    {
        return left->evaluate() / right->evaluate();
    }

    return 0;
}
