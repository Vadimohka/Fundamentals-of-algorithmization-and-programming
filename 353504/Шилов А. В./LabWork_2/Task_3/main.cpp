#include <iostream>
#include "expression.h"

int main()
{
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    std::cout << expr->Evaluate() << std::endl;

    delete expr;

    return 0;
}
