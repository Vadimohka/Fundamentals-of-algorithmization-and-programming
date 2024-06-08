#ifndef MY_HASH_TABLE_H
#define MY_HASH_TABLE_H

#include <QVector>
#include "my_stack.h"

class MyHashTable {
private:
    bool isPrime(int n);
    int getNextPrime(int n);
    int hashFunction(int key);
public:
    int h_size;
    QVector<my_stack> h_table;
    void insert(int key, int value);
    void remove(int key);
    MyHashTable(int initialCapacity);
    void generateRandomTable(int numItems);
    int findMinKeyStack() const;
    QVector<QVector<int>> display();
    void clear();
};

#endif // MY_HASH_TABLE_H
