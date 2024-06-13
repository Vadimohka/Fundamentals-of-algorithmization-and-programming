//
// Created by shosh on 5/29/24.
//

#ifndef LABWORK_7_HASHTABLE_H
#define LABWORK_7_HASHTABLE_H


#include <QByteArray>
#include <QCryptographicHash>
#include "QDebug"
#include "QPair"
#include "QVector"

class HashTable {
   int capacity;
   int size = 0;
   QVector<QPair<int, int>> table;
public:
   HashTable(int capacity);
   void insertItem(int key,int value, QByteArray hashingFunc(int));
   void deleteItem(int key);
   int findItem(int data, QByteArray hashingFunc(int));
   void reserve(int new_cap, QByteArray(*hashingFunc)(int));
   static QByteArray ShaHashing(int num);
   static QByteArray UniversalHashing(int number);
};

static int getNextPrime(int num) {
    auto isPrime = [=](int num) {
        if (num <= 1) {
            return false;
        }
            for (int i = 2; i * i < num; i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
    };
    while (!isPrime(num)) {
        num++;
    }
    return num;
}
#endif //LABWORK_7_HASHTABLE_H
