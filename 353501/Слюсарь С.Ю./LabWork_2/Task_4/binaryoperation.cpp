#include "binaryoperation.h"
BinaryOperation::BinaryOperation(Expression *num1, char op, Expression *num2) : Number()
{
    if (op == 42)
    {
        value_ = num1->evaluate() * num2->evaluate();
    }
    else if (op == 43)
    {
        value_ = num1->evaluate() + num2->evaluate();
    }
    else if (op == 45)
    {
        value_ = num1->evaluate() - num2->evaluate();
    }
    else if (op == 47)
    {
        value_ = num1->evaluate() / num2->evaluate();
    }
    num1_ = num1;
    num2_ = num2;
}

BinaryOperation::~BinaryOperation()
{
    delete num1_;
    delete num2_;
}

double BinaryOperation::evaluate()
{
    return value_;
}
