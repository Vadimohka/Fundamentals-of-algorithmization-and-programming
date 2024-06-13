#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"
#include <vector>
#include <string>

class HashTable {
public:
    HashTable(int size);
    void insert(int key, int value);
    void remove(int key);
    int getValue(int key) const;
    Stack getStack(int index) const;
    std::string toString() const;
    int getSize() const;
    int hashFunction(int key) const;

protected:
    std::vector<Stack> table;
    int tableSize;
};

#endif // HASHTABLE_H
