#include <iostream>
#include "binaryoperation.h"
#include "expression.h"
#include "number.h"

bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

int main()
{
    Number *num1 = new Number(1.5);
    Number *num2 = new Number(2.5);
    BinaryOperation *binop = new BinaryOperation(num1, '+', num2);

    Expression* ptr1 = num1;
    Expression* ptr2 = num1;
    Expression* ptr3 = num2;
    Expression* ptr4 = binop;

    std::cout << *(double **)num1 << "\t" << *(double **)num2 << "\t" << *(double **)binop << "\n";
    std::cout << std::boolalpha;
    std::cout << check_equals(ptr1, ptr2) << std::endl;  // true
    std::cout << check_equals(ptr1, ptr3) << std::endl;  // true
    std::cout << check_equals(ptr1, ptr4) << std::endl;  // false
    delete num1;
    delete num2;
    delete binop;
    return 0;
}
