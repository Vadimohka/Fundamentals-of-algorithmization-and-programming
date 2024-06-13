#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <QPair>

class HashTable {
private:
    int capacity;
    QVector<QPair<int, int>> table;

    bool isPrime(int n);
    int getNextPrime(int n);
    int hashFunction(int key);

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    QVector<QPair<int, int>> displayHash();
    void clear();
    int findItem(int);
};

#endif // HASHTABLE_H
