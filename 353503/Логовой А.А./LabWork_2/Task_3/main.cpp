#include "checkequals.h"
#include <QApplication>
#include <expression.h>
#include <binaryoperation.h>
#include <number.h>


int main(){

    Expression* sube = new BinaryOperation(new Number(4.5), '-', new Number(5));

    Expression* expr = new BinaryOperation(new Number(3), '+', sube);

    Expression *numb = new Number(4);

    Expression* num = new Number(8.101);

    qDebug() << expr->evaluate();

    if(check_equals(numb, expr))
        qDebug() << "Pointers indecates on the same class";
    else
        qDebug() << "Different pointers, they indecates on different clases";

    if(check_equals(numb, num))
        qDebug() << "Pointers indecates on the same class";
    else
        qDebug() << "Different pointers, they indecates on different clases";

    delete num;
    delete expr;
}
