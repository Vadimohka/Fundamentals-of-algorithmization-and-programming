#include <QCoreApplication>
#include "expression.h"
#include "number.h"
#include "binaryoperation.h"

bool check_equals(Expression const *left, Expression const *right)
{
    return ((void(*(*(&)[0])))left)[0][0] == ((void(*(*(&)[0])))right)[0][0];
}

int main()
{
    Number *firstNumber= new Number(1);
    Number *secondNumber = new Number(2);
    auto *firstOperation = new BinaryOperation(firstNumber, '*', secondNumber);
    qDebug() << check_equals(firstNumber, secondNumber);
    qDebug() << check_equals(firstOperation, firstNumber);
}
