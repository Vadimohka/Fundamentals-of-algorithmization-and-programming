#include <iostream>
#include "Expression.h"
#include "Number.h"
#include "BinaryOperation.h"

bool isTheSame(Expression *ex1, Expression *ex2){
    return *(unsigned long long*)ex1 == *(unsigned long long*)ex2;
}

int main() {
    Expression *e1 = new Number(10);
    Expression *e2 = new Number(15);
    Expression *op = new BinaryOperation(e1, e2, BinaryOperation::Operation::DIVIDE);
    std::cout<<isTheSame(e1, e2)<<' '<<isTheSame(e1, op)<<' '<<isTheSame(e2, op)<<'\n';
    std::cout<<op->evaluate()<<'\n';


    unsigned long long address = *(unsigned long long*)op;
    typedef double(*pFun)(void*);
    pFun printFun = (pFun)(*(unsigned long long*)(address));

    std::cout<<printFun(op);
    return 0;
}
