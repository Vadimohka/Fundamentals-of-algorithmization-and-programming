#include "hashtable.h"

HashTable::HashTable(int V) {
    capacity = getNextPrime(V);
    table.resize(capacity);
}

bool HashTable::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int HashTable::getNextPrime(int n) {
    while (!isPrime(n))
        n++;
    return n;
}

int HashTable::hashFunction(int key) {
    return key % capacity;
}

void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push(data);
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    table[index].pop();
}

QVector<QVector<int>> HashTable::displayHash() {
    QVector<QVector<int>> result;
    for (int i = 0; i < capacity; i++) {
        QVector<int> slotContent = table[i].toQVector();
        result.append(slotContent);
    }
    return result;
}

void HashTable::clear() {
    for (auto & i : table) {
        i.clear();
    }
}
