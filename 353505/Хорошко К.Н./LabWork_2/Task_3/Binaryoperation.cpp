#include "Binaryoperation.h"

BinaryOperation::BinaryOperation(Expression *x1, char operat, Expression *x2) : Expression(){
    val1 = x1;
    val2 = x2;
    type = operat;
}

double BinaryOperation::evaluate(){
    switch (type){
    case '*':
        return (val1->evaluate() * val2->evaluate());
        break;
    case '+':
        return (val1->evaluate() + val2->evaluate());
        break;
    case '-':
        return (val1->evaluate() - val2->evaluate());
        break;
    case '/':
        return (val1->evaluate() / val2->evaluate());
        break;
    default:
        return (0);
        break;
    }

}

BinaryOperation::~BinaryOperation(){
    delete(val1);
    delete(val2);
}
