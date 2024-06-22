#include "extendedhashtable.h"
#include <QRandomGenerator>

ExtendedHashTable::ExtendedHashTable(int size) : HashTable(size)
{

}

int ExtendedHashTable::findMaxKey()
{
    int maxKey = 0;
    for (int i = 0; i < size; ++i) {
        for (auto pair : table[i]) {
            if (pair.first > maxKey)
                maxKey = pair.first;
        }
    }
    return maxKey;
}

void ExtendedHashTable::insertRandomData()
{
    QVector<QPair<int, QString>> randomData = getRandomData(5);
    for (auto pair : randomData) {
        insert(pair.first, pair.second);
    }
}

QVector<QPair<int, QString>> ExtendedHashTable::getRandomData(int count)
{
    QVector<QPair<int, QString>> data;
    for (int i = 0; i < count; ++i) {
        int key = QRandomGenerator::global()->bounded(100);
        QString value = "Value_" + QString::number(i);
        data.append(qMakePair(key, value));
    }
    return data;
}

