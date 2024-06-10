#include <iostream>
#include "expression.h"

bool check_equals(Expression const* left, Expression const* right)
{
    return *(void**)left == *(void**)right;
}
int main()
{
    Expression* operation1 = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* operation2 = new BinaryOperation(new Number(3), '+', operation1);
    Expression* number1 = new Number(1);
    Expression* number2 = new Number(2);

    std::cout << check_equals(operation1, operation2) << std::endl;
    std::cout << check_equals(number1, operation2) << std::endl;
    std::cout << check_equals(number1, number2) << std::endl;

    delete operation2;
    delete number1;
    delete number2;
}
