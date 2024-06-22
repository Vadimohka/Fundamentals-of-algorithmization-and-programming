#include "binaryoperation.h"

BinaryOperation::BinaryOperation() {}

BinaryOperation::~BinaryOperation()
{
    delete left;
    delete right;
}

BinaryOperation::BinaryOperation(Expression *left, char type, Expression *right) : left(left), type(type), right(right)
{

}

double BinaryOperation::count()
{
    if (type == '+'){
        return left->count() + right->count();
    }
    else if (type == '-'){
        return left->count() - right->count();
    }
    else if (type == '*'){
        return left->count() * right->count();
    }
    else if (type == '/'){
        return left->count() / right->count();
    }
    return 0;
}
