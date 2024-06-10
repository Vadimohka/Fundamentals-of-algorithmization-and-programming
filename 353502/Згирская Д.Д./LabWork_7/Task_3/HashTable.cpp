#include "HashTable.h"


HashTable::HashTable() {
    hashTable = new Stek[4];
    _size = 4;
}

HashTable::HashTable(uint size) {
    hashTable = new Stek[size];
    _size = size;
}

int HashTable::hashFunction(std::string key) {
    int hashKey = 0;
    for (char ch : key) {
        hashKey += ch;
    }
    std::srand(hashKey);

    return std::rand() % _size;
}

void HashTable::insert(std::string key, int value) {
    int index = hashFunction(key);
    if (index < _size)
        hashTable[index].push_back(value);
    else {
        Stek* newTable = new Stek[index];
        for (int i = 0; i < _size; ++i) {
            newTable[i] = hashTable[i];
            /*for (int j = 0; j < hashTable[i].size(); ++j) {

            }*/
        }
    }
    _size += 1;
}

void HashTable::deleteKey(std::string key) {
    int index = hashFunction(key);
    if (!hashTable[index].isEmpty()) {
        hashTable[index].pop_back();
        --_size;
    }
}

int HashTable::searchValue(std::string key) {
    int index = hashFunction(key);
    if (!hashTable[index].isEmpty()) {
        return hashTable[index].peek_back();
    }
    return 0;
}

void HashTable::clear() {
    for (int i = 0; i < _size; ++i) {
        hashTable[i].clear();
    }
}

uint HashTable::size() {
    return _size;
}

QString HashTable::print() {
    QString result;
    for (int i = 0; i < _size; ++i) {
        result += "Index " + QString::number(i) + ": " + hashTable[i].toString() + "\n";
    }
    return result.trimmed();
}