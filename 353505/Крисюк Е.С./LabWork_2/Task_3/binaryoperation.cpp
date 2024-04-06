#include "binaryoperation.h"

BinaryOperation::BinaryOperation() {}

BinaryOperation::~BinaryOperation()
{
    delete operand_right;
    delete operand_left;
}

BinaryOperation::BinaryOperation(Expression *left, char initOperation, Expression *right)
{
    operand_left = left;
    operand_right = right;
    operation = initOperation;
}

double BinaryOperation::evaluate()
{

    if(operation == '+'){
        return operand_left -> evaluate() + operand_right -> evaluate();
    }
    else if(operation == '-'){
        return operand_left -> evaluate() - operand_right -> evaluate();
    }
    else if(operation == '*'){
        return operand_left -> evaluate() * operand_right -> evaluate();
    }
    else if(operation == '/'){
        return operand_left -> evaluate() / operand_right -> evaluate();
    }
    return 0;
}
