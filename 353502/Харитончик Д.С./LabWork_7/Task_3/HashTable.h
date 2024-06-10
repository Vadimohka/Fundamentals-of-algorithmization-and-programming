#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "qdebug.h"
#pragma once
#include "Stack.h"
#include "primes.h"
#include <QVector>

class HashTable {
protected:
    int capacity = 1;
    QVector<Stack> table;
    int getNextPrime(int n) {
        int l = 0, r = primes.size() - 1;
        while (qAbs(l - r) > 1) {
            int m = (l + r) / 2;
            if (primes[m] > n) r = m;
            else l = m;
        }
        return primes[r];
    }
    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int V) {
        capacity = getNextPrime(V);
        table.resize(capacity);
    }
    void insertItem(int key, int data) {
        table[hashFunction(key)].push(data);
    }
    void deleteItem(int key){
        table[hashFunction(key)].pop();
    }
    QVector<QVector<int>> displayHash(){
        QVector<QVector<int>> result;
        for (int i = 0; i < capacity; i++)
            result.append(table[i].toQVector());
        return result;
    }
    void clear();
};

#endif // HASHTABLE_H
