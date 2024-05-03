#include <iostream>
#include "expression.h"
#include "number.h"
#include "binaryoperation.h"

int main() {
    Expression *firstOperation = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *secondOperation = new BinaryOperation(new Number(3), '+', firstOperation);
    qDebug() << secondOperation->evaluate();
}
