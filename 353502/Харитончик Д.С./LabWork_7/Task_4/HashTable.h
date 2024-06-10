#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <QPair>
#include <QThread>

class QuadHashTable {
private:
    int capacity = 1;
    QVector<QPair<int, int>> table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    QuadHashTable(int V) {
        capacity = V;
        table.resize(capacity);
    }
    void insertItem(int key, int data) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != 0 && cnt++ < capacity + 1) {
            index = (index * index + index + 1) % capacity;
        }
        table[index] = qMakePair(key, data);
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < capacity + 1) {
            index = (index * index + index + 1) % capacity;
        }
        if (table[index].first == key) {
            table[index] = qMakePair(0, 0);
        }
    }
    QVector<QPair<int, int>> displayHash(){
        return table;
    }
    void clear() {
        table.fill(qMakePair(0, 0));
    }
    int findItem(int key) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < capacity + 1) {
            index = (9 * index + 1) % capacity;
        }
        if (table[index].first == key) {
            return table[index].second;
        }
        return -1;
    }
};

class LinearHashTable {
private:
    int capacity = 1;
    QVector<QPair<int, int>> table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    LinearHashTable(int V) {
        capacity = V;
        table.resize(capacity);
    }
    void insertItem(int key, int data) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != 0 && cnt++ < capacity + 1) {
            index = (index + 1) % capacity;
        }
        table[index] = qMakePair(key, data);
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < capacity + 1) {
            index = (index + 1) % capacity;
        }
        if (table[index].first == key) {
            table[index] = qMakePair(0, 0);
        }
    }
    QVector<QPair<int, int>> displayHash(){
        return table;
    }
    void clear() {
        table.fill(qMakePair(0, 0));
    }
    int findItem(int key) {
        int index = hashFunction(key);
        int cnt = 0;
        while (table[index].first != key && table[index].first != 0 && cnt++ < capacity + 1) {
            index = (index + 1) % capacity;
        }
        if (table[index].first == key) {
            return table[index].second;
        }
        return -1;
    }
};

#endif // HASHTABLE_H
