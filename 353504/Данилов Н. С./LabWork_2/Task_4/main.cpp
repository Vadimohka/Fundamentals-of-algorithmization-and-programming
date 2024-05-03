#include "expression.h"
#include "number.h"
#include "binaryoperation.h"
#include <iostream>
bool check_equals(Expression const* left, Expression const* right) {
    return  *(int *)left == *(int *)right;
}

int main()
{
    auto a = new Number(2);
    auto b = new Number(1);
    auto c = new BinaryOperation(b, '+', a);
    std::cout << *(int *)a << ' ' << *(int *)b << ' ' << *(int *)c;
    int qq;
    std::cin >> qq;
    return 0;
}
