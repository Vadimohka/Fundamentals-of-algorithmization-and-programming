#include "binaryoperation.h"

void BinaryOperation::Calc(double num_1, double num_2, char operation)
{
    if(operation == '+'){
        number = num_1 + num_2;
        return;
    }
    if(operation == '-'){
        number = num_1 - num_2;
        return;
    }
    if(operation == '*'){
        number = num_1 * num_2;
        return;
    }
    if(operation == '/'){
        number = num_1 / num_2;
        return;
    }

    number = 0;
    qDebug() << "Unluck navernoe(";
}

double BinaryOperation::evaluate()
{
    return number;
}

BinaryOperation::~BinaryOperation()
{
    delete num_1;
    delete num_2;
}
BinaryOperation::BinaryOperation(Expression *expr_1, char operation, Expression *expr_2)
{
    Calc(expr_1->evaluate(), expr_2->evaluate(), operation);
}
