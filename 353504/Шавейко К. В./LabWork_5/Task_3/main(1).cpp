#include <iostream>
#include "mybitset.h"

int main() {
    // Создание BitSet и установка некоторых битов
    BitSet<10> bs1(1513);
    bs1.set(1);
    bs1.set(3);
    bs1.set(5);
    bs1.set(7);
    bs1[9] = true;

    // Вывод BitSet на экран
    std::cout << "bs1: " << bs1 << std::endl;

    // Проверка оператора []
    std::cout << "Bit at position 3 in bs1: " << bs1[3] << std::endl;

    // Проверка метода test()
    std::cout << "Bit at position 4 in bs1: " << bs1.test(4) << std::endl;

    // Проверка методов all(), any() и none()
    std::cout << "All bits set in bs1? " << bs1.all() << std::endl;
    std::cout << "Any bits set in bs1? " << bs1.any() << std::endl;
    std::cout << "No bits set in bs1? " << bs1.none() << std::endl;

    // Проверка метода count()
    std::cout << "Number of set bits in bs1: " << bs1.count() << std::endl;

    // Создание копии BitSet
    BitSet<10> bs2(bs1);

    // Вывод копии на экран
    std::cout << "bs2 (copy of bs1): " << bs2 << std::endl;

    // Проверка операторов сравнения
    std::cout << "bs1 == bs2? " << (bs1 == bs2) << std::endl;
    std::cout << "bs1 != bs2? " << (bs1 != bs2) << std::endl;

    // Выполнение логических операций
    BitSet<10> bs3;
    bs3.set(2);
    bs3.set(3);
    bs3.set(6);
    bs3.set(8);
    std::cout << "bs3: " << bs3 << std::endl;

    std::cout << "bs1 & bs3: " << (bs1 & bs3) << std::endl;
    std::cout << "bs1 | bs3: " << (bs1 | bs3) << std::endl;
    std::cout << "bs1 ^ bs3: " << (bs1 ^ bs3) << std::endl;

    // Использование метода flip()
    bs1.flip(3);
    std::cout << "bs1 after flipping bit at position 3: " << bs1 << std::endl;

    // Использование метода reset()
    bs1.reset(3);
    std::cout << "bs1 after resetting bit at position 3: " << bs1 << std::endl;

    return 0;
}
