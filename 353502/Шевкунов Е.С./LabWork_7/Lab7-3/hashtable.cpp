#include "hashtable.h"
#include <QDebug>

HashTable::HashTable(int size)
{
    this->size = size;
    table = new QVector<QPair<int, QString>>[size];
}

void HashTable::insert(int key, const QString& value)
{
    int index = hash(key);
    table[index].append(qMakePair(key, value));
}

QString HashTable::find(int key)
{
    int index = hash(key);
    for (auto pair : table[index]) {
        if (pair.first == key)
            return pair.second;
    }
    return QString("Key not found");
}

void HashTable::printTable()
{
    for (int i = 0; i < size; ++i) {
        qDebug() << "Bucket " << i << ": ";
        for (auto pair : table[i]) {
            qDebug() << "(" << pair.first << ", " << pair.second << ")";
        }
    }
}

int HashTable::hash(int key)
{
    return key % size;
}
