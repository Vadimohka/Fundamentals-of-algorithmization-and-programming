#include <iostream>
#include <cstring>
#include "BinaryOperation.h"
#include "Number.h"

bool check_equals(Expression const* left, Expression const* right)
{
    // Compare the memory layouts of the two objects
    return (*((size_t*)left) == *((size_t*)right));
}

int main()
{
    Expression* cube = new BinaryOperation(new Number(4.5), '*', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', cube);
    std::cout << expr->evaluate() << std::endl;

    Expression* expr1 = new BinaryOperation(new Number(3), '+', new Number(4));
    std::cout << expr1->evaluate() << std::endl; // Output: 7

    Expression* expr2 = new BinaryOperation(new Number(10), '-', new Number(5));
    std::cout << expr2->evaluate() << std::endl; // Output: 5

    Expression* expr3 = new BinaryOperation(new Number(20), '/', new Number(4));
    std::cout << expr3->evaluate() << std::endl; // Output: 5

    delete expr;
    delete expr1;
    delete expr2;
    delete expr3;
    return 0;
}
