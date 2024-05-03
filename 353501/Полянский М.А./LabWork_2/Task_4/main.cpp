#include <iostream>
#include "BinaryOperation.h"
#include "Number.h"
#include "Expression.h"
bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

int main(){
    Number* num1 = new Number(12.1);
    Number* num2 = new Number(1.2);
    BinaryOperation* bin1 =  new BinaryOperation(num1, '-', num2);
    BinaryOperation* bin2 =  new BinaryOperation(num1, '*', num2);
    std::cout<< *(double**)num1 << '\n' << *(double**) num2 << '\n' << *(double **) bin1 << '\n' << *(double ** ) bin2 << '\n';
    std::cout<< (check_equals(bin1, bin2) ? "Yes\n" : "No\n");
    std::cout<< (check_equals(num1, bin2) ? "Yes\n" : "No\n");

    return 0;
}