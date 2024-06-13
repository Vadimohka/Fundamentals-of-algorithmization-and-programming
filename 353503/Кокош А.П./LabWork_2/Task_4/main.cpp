#include "binaryoperation.h"
#include "number.h"

bool check_equals(Expression const *left, Expression const *right)
{
    return typeid(*left) == typeid(*right);
}

int main()
{
    Number *a = new Number(2.5);
    Number *b = new Number(4.5);
    Expression *first = new BinaryOperation(a, '+', b);
    Expression *second = new BinaryOperation(a, '/', first);
    std::cout << second->evaluate() << '\n';
    std::cout << "a = " << typeid(a).name() << '\n';
    std::cout << "b = " << typeid(b).name() << '\n';
    std::cout << "first = " << typeid(first).name() << '\n';
    std::cout << "second = " << typeid(second).name() << '\n';
    std::cout << (check_equals(a, b) ? "Yes\n" : "No\n");
    std::cout << (check_equals(a, second) ? "Yes\n" : "No\n");
    delete first;
    delete second;
}
