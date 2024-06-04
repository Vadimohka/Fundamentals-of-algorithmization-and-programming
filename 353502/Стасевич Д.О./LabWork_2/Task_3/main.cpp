#include <iostream>
#include "Expression.h"
#include "Number.h"
#include "BinaryOperation.h"

BinaryOperation* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
BinaryOperation* expr = new BinaryOperation(new Number(3), '+', sube);
Number* num = new Number(5);

double (Expression::*fptr)();

bool check_equals(Expression *left, Expression *right)
{
    long long *a1 = *(long long**)(left);
    long long *a2 = *(long long**)(right);
    return (a1 == a2);
}

int main() {
    std::cout << sube->evaluate() << " " << expr->evaluate();
    delete expr;
}
