#include <iostream>
#include "../Task3/expression.h"
#include "../Task3/number.h"
#include "../Task3/binaryOperation.h"

bool check_equals(Expression const *left, Expression const *right) {
    return *(void**)left == *(void**)right;
}

int main(int, char**){
    Number *num1 = new Number(25);
    Number *num2 = new Number(14);
    BinaryOperation *operation1 = new BinaryOperation(num1, '-', num2);
    BinaryOperation *operation2 = new BinaryOperation(num1, '/', num2);
    
    std::cout << num1->getValue() << "\t" <<  *(void **)num1 << "\n"
              << num2->getValue() << "\t" <<  *(void **)num2 << "\n"
              << operation1->getValue() << "\t" << *(void **)operation1 << "\n"
              << operation2->getValue() << "\t" << *(void **)operation2 << "\n\n";

    std::cout << (check_equals(operation1, operation2) ? "Yes\n" : "No\n");
    std::cout << (check_equals(num1, operation2) ? "Yes\n" : "No\n");
}
