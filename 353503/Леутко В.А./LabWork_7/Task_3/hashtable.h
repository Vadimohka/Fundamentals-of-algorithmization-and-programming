#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
#include <cstdint>
#include "stack.h"

template<typename T>
class HashTable
{
protected:
    Stack<T> *table;

private:
    size_t _size;

    int64_t hashFunction(int64_t key);

public:
    explicit HashTable(size_t sizeTable);
    virtual ~HashTable();

    size_t size() const;
    virtual void insert(int64_t key, T value);
    T find(int64_t key);
};

#endif // HASHTABLE_H
