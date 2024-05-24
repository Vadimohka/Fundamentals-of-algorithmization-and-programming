#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QVector>
#include "mystack.h"

class MyHashTable {
private:
    int m_capacity;
    QVector<MyStack> m_table;
    bool isPrime(int n);
    int getNextPrime(int n);
    int hashFunction(int key);
public:
    void generateRandomTable(int minKey, int maxKey, int numItems);
    int findMinKeyStack() const;
    MyHashTable(int initialCapacity);
    void insert(int key, int value);
    void remove(int key);
    QVector<QVector<int>> display() const;
    void clear();
};

#endif // MYHASHTABLE_H
