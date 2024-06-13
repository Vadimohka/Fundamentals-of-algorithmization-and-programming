#ifndef MYBST_H
#define MYBST_H
#include "qdebug.h"
#pragma once
#include <QVector>
#include "MyPrimes.h"
#include "Stack.h"

class HashTable {
protected:
    int tableSize = 1;
    QVector<Stack> table;
    int getNextPrime(int n) {
        int l = 0, r = MyPrimes.size() - 1;
        while (qAbs(l - r) > 1) {
            int m = (l + r) / 2;
            if (MyPrimes[m] > n)
                r = m;
            else l = m;
        }
        return MyPrimes[r];
    }
    int hashFunction(int key) { return key % tableSize; }

public:
    HashTable(int size)
    {
        tableSize = getNextPrime(size);
        table.resize(tableSize);
    }
    void insertItem(int key, int data) { table[hashFunction(key)].push(key, data); }
    void deleteItem(int key) { table[hashFunction(key)].pop(); }

    QVector<int> searchItem(int key) { return table[hashFunction(key)].toQVectorValue(); }

    QVector<QVector<int>> displayHash()
    {
        QVector<QVector<int>> result;
        for (int i = 0; i < tableSize; i++)
            result.append(table[i].toQVectorValue());
        return result;
    }
    void clear();
};

#endif // HASHTABLE_H
