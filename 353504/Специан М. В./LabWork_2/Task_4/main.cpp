#include "../task3/expression.h"
#include "../task3/number.h"
#include "../task3/binaryoperation.h"

#include <iostream>


bool check_equals(Expression const* left, Expression const* right) {
    return (left->isNumber() && right->isNumber()) ||
           (left->isBinaryOperation() && right->isBinaryOperation());
}

int main(/*int argc, char *argv[]*/){
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << std::endl;
    Expression *r = new Number(2);

    if (check_equals(expr, sube))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";
    if (check_equals(r, r))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";
    if (check_equals(r, sube))
        std::cout << "equal\n";
    else
        std::cout << "unequal\n";

    delete expr;

    return 0;
}
