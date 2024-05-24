#include <QCoreApplication>

#include "dvector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Создаем объект Dvector с начальной емкостью 10
    Dvector<int> vec(10);

    // Добавляем элементы в вектор
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // Выводим элементы вектора
    qDebug() << "Vector elements:";
    for (Iterator<int> it = vec.begin(); it != vec.end(); ++it) {
        qDebug() << *it;
    }
    vec.pop_back();
    qDebug() << "Size after pop_back():" << vec.Size();
    vec.erase(3);
    qDebug() << "Size after erase(3):" << vec.Size();
    // Выводим размер и емкость вектора
    qDebug() << "Size:" << vec.Size();
    qDebug() << "Capacity:" << vec.Capacity();

    // Удаляем последний элемент вектора
    vec.pop_back();

    // Выводим элементы после удаления
    qDebug() << "Vector elements after pop_back():";
    for (Iterator<int> it = vec.begin(); it != vec.end(); ++it) {
        qDebug() << *it;
    }
    // Пример использования swap
    Dvector<int> vec2(5); // Создаем второй вектор
    vec2.push_back(100);
    vec.swap(vec2); // Обмениваем содержимое vec и vec2

    qDebug() << "Vector elements:";
    for (Iterator<int> it = vec.begin(); it != vec.end(); ++it) {
        qDebug() << *it;
    }
    return a.exec();
}
