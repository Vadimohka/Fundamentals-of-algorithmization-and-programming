#include <QCoreApplication>

#include "binaryoperation.h"
#include "number.h"


bool check_equals(Expression const* left, Expression const* right){
    return *(void**)left == *(void**)right;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    qDebug() << expr->evaluate() << '\n';
    return a.exec();
}
