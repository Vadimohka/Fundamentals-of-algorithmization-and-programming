//
// Created by zgdarya on 5/30/24.
//

#ifndef L7_T3_HASHTABLE_H
#define L7_T3_HASHTABLE_H


#include <string>
#include <QString>
#include "Stek.h"

class HashTable {
    Stek* hashTable;
    uint _size;

public:
    HashTable();
    HashTable(uint size);
    int hashFunction(std::string  key);
    void insert(std::string key, int value);
    void deleteKey(std::string key);
    int searchValue(std::string key);
    void clear();
    uint size();
    QString print();
};


#endif //L7_T3_HASHTABLE_H
