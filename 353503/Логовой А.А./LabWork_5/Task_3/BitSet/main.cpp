#include <QDebug>
#include "BitSet.h"

int main() {
    constexpr size_t N = 32;
    BitSet<N> bs;

    qDebug() << "Начальное состояние битсета: " << bs.to_string();

    bs.set(0).set(5).set(10).set(31);
    qDebug() << "После установки бит: " << bs.to_string();

    bs.reset(0).reset(31);
    qDebug() << "После сброса бит: " << bs.to_string();

    bs.flip(5).flip(10);
    qDebug() << "После инвертирования бит: " << bs.to_string();

    qDebug() << "Бит 5 установлен: " << bs.test(5);
    qDebug() << "Бит 10 установлен: " << bs.test(10);

    qDebug() << "Строковое представление: " << bs.to_string();
    qDebug() << "Как unsigned long long: " << bs.to_ullong();
    qDebug() << "Как unsigned long: " << bs.to_ulong();

    qDebug() << "Все биты установлены: " << bs.all();
    qDebug() << "Хотя бы один бит установлен: " << bs.any();
    qDebug() << "Ни один бит не установлен: " << bs.none();
    qDebug() << "Количество установленных битов: " << bs.count();

    BitSet<N> bs2 = ~bs;
    qDebug() << "Инвертированный битсет: " << bs2.to_string();

    BitSet<N> bs3 = bs & bs2;
    qDebug() << "Пересечение битсетов: " << bs3.to_string();

    BitSet<N> bs4 = bs | bs2;
    qDebug() << "Объединение битсетов: " << bs4.to_string();

    return 0;
}
