#include "myhashtable.h"
#include <QRandomGenerator>

void MyHashTable::createRandomHashTable() {
    int n = QRandomGenerator::global()->bounded(0, 1000);
    for (int i = 0; i < n; ++i) {
        insertItem(QRandomGenerator::global()->bounded(0, capacity), QRandomGenerator::global()->bounded(0, 100));
    }
}

QVector<int> MyHashTable::findMaxKey() {
    int maxKey = 0;
    for (int i = 1; i < capacity; ++i) {
        if (!table[i].isEmpty() && i > maxKey) {
            maxKey = i;
        }
    }
    return table[maxKey].toQVector();
}
