#include <QCoreApplication>
#include <Expression.h>
#include <Binaryoperation.h>
#include <Number.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +

    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    // вычисляем и выводим результат: 25.5
    qDebug() << expr->evaluate();
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
    return a.exec();
}
