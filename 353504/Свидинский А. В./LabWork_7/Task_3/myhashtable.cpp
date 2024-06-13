#include "myhashtable.h"
#include <QRandomGenerator>

void MyHashTable::createRandomHashTable() {
    int n = QRandomGenerator::global()->bounded(0, 100);
    for (int i = 0; i < n; ++i) {
        insertItem(QRandomGenerator::global()->bounded(0, capacity), QRandomGenerator::global()->bounded(0, 100));
    }
}

QVector<int> MyHashTable::findMinKey() {
    int minKey = capacity; // Инициализируем minKey максимально возможным значением
    for (int i = 0; i < capacity; ++i) {
        if (!table[i].isEmpty() && i < minKey) {
            minKey = i;
        }
    }
    return table[minKey].toQVector(); // Возвращаем стек с минимальным ключом
}
