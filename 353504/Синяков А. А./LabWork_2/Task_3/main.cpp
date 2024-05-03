#include <QCoreApplication>
#include "expression.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
Expression* sube1 = new BinaryOperation(new Number(434.5), '*', new Number(556));
    // Создаем первое выражение: 444.5 * 556


    // Создаем второе выражение: (444.5 * 556) + 3
    Expression* expr1 = new BinaryOperation(sube1, '+', new Number(3));

    // Создаем третье выражение: (444.5 * 556 + 3) / 2
    Expression* expr2 = new BinaryOperation(expr1, '/', new Number(2));

    // Вычисляем результат третьего выражения
    std::cout << "Result: " << (*expr2).evaluate() << std::endl;

    // Освобождаем выделенную память
    delete expr2;
    delete expr1;
    delete sube1;

    return a.exec();
}
