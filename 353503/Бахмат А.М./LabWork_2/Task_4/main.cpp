#include "mainwindow.h"
#include "number.h"
#include "expression.h"
#include "binaryoperation.h"
#include <QApplication>

bool check_equals(Expression* left, Expression* right)
{
    void* l = *(void**)(left);
    void* r = *(void**)(right);
    return l == r;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    qDebug() << check_equals(new Number(4.5), new Number(1));
    qDebug() << check_equals(new Number(4.5), sube);
    // вычисляем и выводим результат: 25.5
    qDebug() << sube->evaluate();
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
}
