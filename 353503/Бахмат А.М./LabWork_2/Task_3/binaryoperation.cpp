#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* expression1, char operation, Expression* expression2)
{
    calculate(expression1 -> evaluate(), operation, expression2 -> evaluate());
}

BinaryOperation::~BinaryOperation()
{
    delete _expression1;
    delete _expression2;
}

void BinaryOperation::calculate(double number1, char operation, double number2)
{
    if(operation == '+')
    {
        _number = number1 + number2;
        return;
    }

    if(operation == '-')
    {
        _number = number1 - number2;
        return;
    }

    if(operation == '*')
    {
        _number = number1 * number2;
        return;
    }

    if(operation == '/')
    {
        _number = number1 * number2;
        return;
    }
}

double BinaryOperation::evaluate()
{
    return _number;
}
