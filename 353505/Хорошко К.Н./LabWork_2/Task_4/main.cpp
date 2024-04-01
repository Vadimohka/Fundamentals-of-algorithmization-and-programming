#include <QCoreApplication>
#include <expression.h>
#include <binaryoperation.h>
#include <number.h>

bool check(Expression const* left, Expression const* right) {
    return (typeid(*left) == typeid(*right));
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* sube2 = new BinaryOperation(new Number(6), '*', new Number(5));
    // потом используем его в выражении для +

    Expression* expr = new Number(1);
    Expression* expr2 = new Number(2);
    // вычисляем и выводим результат: 25.5
    qDebug() << check(sube, expr) << " " << check(expr2, expr);
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return a.exec();
}
