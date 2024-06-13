#include "expression.h"
#include "binaryoperation.h"
#include "number.h"
#include "checkequals.h"

#include "QDebug"


int main(int argc, char *argv[])
{
    Expression* sube = new BinaryOperation(new Number(4.5), '-', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    Expression *numb = new Number(4);

    qDebug() << expr->evaluate();

    delete expr;
}
