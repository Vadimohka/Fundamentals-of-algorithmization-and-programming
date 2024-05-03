#include <QCoreApplication>
#include "expression.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создаем два объекта класса Number
    Expression* num1 = new Number(7);
    Expression* num2 = new Number(5);

    // Создаем два объекта класса BinaryOperation, которые используют эти числа
    Expression* binOp1 = new BinaryOperation(*new BinaryOperation(num1, '+', num2));
    Expression* binOp2 = new BinaryOperation(num1, '+', num2);

    // Проверяем, равны ли они
    std::cout << check_equals(binOp1, binOp2) << std::endl; // Выведет 1, так как операции одинаковые

    // Освобождаем память
    delete num1;
    delete num2;
    delete binOp1;
    delete binOp2;

    return a.exec();
}
/*
bool check_equals(Expression const* ex1, Expression const* ex2) {
  // access the first [size_of_pointer] bytes of class
  // this is where pointer to vtable stored in most of compilers
  return *(uintptr_t*)(ex1) ==
         *(uintptr_t*)(ex2);
}
*/

