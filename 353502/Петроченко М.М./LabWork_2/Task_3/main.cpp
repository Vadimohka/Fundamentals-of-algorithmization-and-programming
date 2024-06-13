#include <iostream>
#include "../headers/BinaryExpression.h"
#include "../headers/Number.h"

bool isSameType(Expression const*, Expression const*);

int main(){


    Number num = Number(6.8);
    Number num2 = Number(0.0000000000000000000000000002);
    BinaryExpression be = BinaryExpression(new Number(1), '+', new Number(1));
    std::cout << num.evaluate() << '\n';
    Expression* sube = new BinaryExpression(new Number(2), '+', new Number(4));
    Expression* e2 = new BinaryExpression(new Number(15), '+', new Number(45));
    Expression* e3 = new Number(0.000000000000000000000000000000000000000000000000000000000000000000000000000002);
    Expression* expr = new BinaryExpression(new BinaryExpression(sube, '-', e2), '/', e3);
    std::cout << expr->evaluate() << '\n';
    isSameType(sube, e3);
    delete expr;
    return 0;
}


bool isSameType(Expression const* left, Expression const* right){
    return *(long long*)(left) == *(long long*)(right);
}