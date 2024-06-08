#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"
#include "stack.cpp"

template <typename T>
class Item {
public:
    int key;
    T value;

    Item(int key, T value)
    {
        this->key = key;
        this->value = value;
    }
};


template <typename T>
class HashTable {
protected:
    Stack<Item<T>>* table;
    int size;

    int hashFunction(int key) const;

public:
    HashTable(int size);
    ~HashTable();

    void insert(int key, T value);
    T get(int key);
    void remove(int key);
};


#endif // HASHTABLE_H
