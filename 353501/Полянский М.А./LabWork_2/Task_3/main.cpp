#include <iostream>
#include "BinaryOperation.h"
#include "Number.h"
#include "Expression.h"
bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

int main(){
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << "\n";
    delete expr;
    return 0;
}