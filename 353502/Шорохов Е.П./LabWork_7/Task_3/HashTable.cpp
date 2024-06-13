//
// Created by shosh on 5/29/24.
//

#include <cstdlib>
#include <ctime>
#include <random>
#include "HashTable.h"

HashTable::HashTable(int capacity) {
    this->capacity = getNextPrime(capacity);
    table.resize(capacity);
}

QByteArray HashTable::ShaHashing(int num) {
    if (num % 2 == 0) {
        return QCryptographicHash::hash(QByteArray::number(num), QCryptographicHash::Sha3_256);
    } else {
        return QCryptographicHash::hash(QByteArray::number(num), QCryptographicHash::Sha1);
    }
}

void HashTable::insertItem(int key, int value, QByteArray (*hashingFunc)(int)) {
    QByteArray Hash = hashingFunc(key);
    size++;
    int index  = ((int)((Hash[0]) & 0xFF)) << 8;
    index += (int)(Hash[1] & 0xFF);
    index %= capacity;
    int temp_index = index;
    while (table[index].first != 0) {
        index = (index + 1) % capacity;
        if (index == temp_index) {
            qDebug() << "Pity for you. Table is full now";
            return;
        }
    }
    if (size > capacity * 7 / 10) {
        reserve(capacity * 2);
    }
    table[index] = qMakePair(key, value);
}

int HashTable::findItem(int key, QByteArray(*hashingFunc)(int)) {
    QByteArray Hash = hashingFunc(key);
    int index  = ((int)((Hash[0]) & 0xFF)) << 8;
    index += (int)(Hash[1] & 0xFF);
    index %= capacity;
    if (table[index].first != 0) {
        return table[index].second;
    }
    return -1;
}

void HashTable::deleteItem(int key) {

}

void HashTable::reserve(int new_cap, QByteArray(*hashingFunc)(int)) {
    new_cap = getNextPrime(new_cap);
    table.resize(new_cap);
    capacity = new_cap;
    for (int i = 0; i < table.size(); i++) {
        if (table[i].first != 0) {
            int key = table[i].first;
            QByteArray Hash = hashingFunc(i);
            int index  = ((int)((Hash[0]) & 0xFF)) << 8;
            index += (int)(Hash[1] & 0xFF);
            index %= capacity;
            int temp_index = index;
            int value = table[i].second;
            while (table[index].first != 0) {
                index = (index + 1) % capacity;
            }
            table[index] = qMakePair(key, value);
        }
    }
}
