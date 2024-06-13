#include "hashTable.h"
#include <QThread>

HashTable::HashTable(int V) {
    capacity = nextSimpleNumber(V);
    table.resize(capacity);
    deleted.resize(capacity);
    wasInserted.resize(capacity);
}

bool HashTable::isSimple(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int HashTable::nextSimpleNumber(int n) {
    while (!isSimple(n))
        n++;
    return n;
}

int HashTable::hashFunction(int key, int i) {
    return (func1(key) + i * func2(key)) % capacity;
}

int HashTable::func1(int key){
    return key % capacity;
}

int HashTable::func2(int key){
    return 1 + key % capacity;
}

bool HashTable::insertItem(int key, int value) {
    for(int i = 0; i < capacity; i++){
        int index = hashFunction(key, i);
        if (deleted[index] || !wasInserted[index]) {
            table[index] = QPair<int, int>(key, value);
            deleted[index] = false;
            wasInserted[index] = true;
            return true;
        }
    }
    capacity = nextSimpleNumber(capacity * 2);
    table.resize(capacity);
    deleted.resize(capacity);
    wasInserted.resize(capacity);
    return false;
}

void HashTable::deleteItem(int key) {
    for(int i = 0; i < capacity; i++){
        int index = hashFunction(key, i);
        if(table[index].first == key && !deleted[index]){
            table[index].second = -1;
            deleted[index] = true;
            wasInserted[index] = false;
            return;
        }
    }
}

int HashTable::search(int key){
    for(int i = 0; i < capacity; i++){
        int index = hashFunction(key, i);
        if(table[index].first == key && !deleted[index]){
            return table[index].second;
        }
    }
    return -1;
}

QVector<QPair<int, int>> HashTable::toVec() {
    QVector<QPair<int, int>> result;
    for (int i = 0; i < capacity; i++) {
        result.append(table[i]);
    }
    return result;
}

void HashTable::clear() {
    deleted.clear();
    table.clear();
    deleted.resize(0);
    table.resize(0);
}
