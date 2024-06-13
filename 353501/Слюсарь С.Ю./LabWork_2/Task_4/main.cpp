#include <QCoreApplication>
#include <QDebug>
#include "binaryoperation.h"
bool check_equals(const Expression *left, const Expression *right);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << check_equals(new BinaryOperation(new Number(-10.5), '*', new Number(5)), new BinaryOperation(new Number(9), '*', new Number(8)));
    qDebug() << check_equals(new BinaryOperation(new Number(-10.5), '*', new Number(5)), new Number(65));
    return a.exec();
}

bool check_equals(const Expression *left, const Expression *right)
{
    return *(long long*)left == *(long long*)right;
}
