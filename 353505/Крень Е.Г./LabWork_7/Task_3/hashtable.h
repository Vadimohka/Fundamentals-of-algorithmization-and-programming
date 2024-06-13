#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include "stack.h"

class HashTable {
protected:
    int capacity;
    QVector<Stack> table;

    bool isPrime(int n);
    int getNextPrime(int n);
    int hashFunction(int key);

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    QVector<QVector<int>> displayHash();
    void clear();
};

#endif // HASHTABLE_H
