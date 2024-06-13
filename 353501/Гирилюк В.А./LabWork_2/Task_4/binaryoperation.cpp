#include "binaryoperation.h"

BinaryOperation::BinaryOperation(Expression* operand1, char operation, Expression* operand2)
{
    this->operand1 = operand1;
    this->operand2 = operand2;
    this->operation = operation;
}

BinaryOperation::~BinaryOperation()
{
    delete[] operand1;
    delete[] operand2;
}

double BinaryOperation::evaluate()
{
    if(operation == '+'){
        return operand1->evaluate() + operand2->evaluate();
    }
    else if(operation == '-'){
        return operand1->evaluate() - operand2->evaluate();
    }
    else if(operation == '*'){
        return operand1->evaluate() * operand2->evaluate();
    }
    else if(operation == '/'){
        return operand1->evaluate() / operand2->evaluate();
    }
    else{
        return 0;
    }
}
