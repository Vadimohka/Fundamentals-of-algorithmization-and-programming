#include <iostream>
#include <QDebug>
#include "number.h"
#include "binaryoperation.h"


bool check_equals(Expression* left,Expression* right){

    if(*(double*)left == *(double*)right){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    int* a = 0;

    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << expr->evaluate() << std::endl;

    if(check_equals(sube,expr)){
        std::cout << "Yes\n";
    }
    else{
        std::cout << "No\n";
    }
    delete expr;
    return 0;
}
