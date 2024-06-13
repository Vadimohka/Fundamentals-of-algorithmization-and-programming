#ifndef MODHASHTABLE_H
#define MODHASHTABLE_H
#pragma once

#include <QPair>
#include <cstddef>

template<typename T>
class ModHashTable
{
private:
    std::pair<long long, T> *node;
    size_t _size;
    size_t _amountСollisions;

    long long hashFunction(long long key) { return key % _size; }

public:
    explicit ModHashTable(size_t sizeTable)
        : node(new std::pair<long long, T>[sizeTable])
        , _size(sizeTable)
        , _amountСollisions(0)
    {}

    ~ModHashTable() { delete[] node; }

    size_t size() const { return _size; }

    size_t amountСollisions() const { return _amountСollisions; }

    void clear()
    {
        for (size_t i = 0; i < _size; ++i) {
            node[i].second = NULL;
        }
        _amountСollisions = 0;
    }

    void insert(long long key, T value)
    {
        size_t pos = hashFunction(key);
        if (node[pos].second != NULL) {
            bool flag = false;
            for (size_t i = 0; i < _size; i++) {
                if (node[(pos + i) % _size].second == NULL) {
                    node[pos].first = key;
                    node[pos].second = value;
                    flag = true;
                }
            }
            if (!flag) {
                throw("Нельзя добавить");
            }
            ++_amountСollisions;
        } else {
            node[pos].first = key;
            node[pos].second = value;
        }
    }

    T find(long long key)
    {
        size_t pos = hashFunction(key);
        if (node[pos].first != key) {
            for (size_t i = 0; i < _size; i++) {
                if (node[(pos + i) % _size].first == key) {
                    return node[(pos + i) % _size].second;
                }
            }
            return NULL;
        } else {
            return node[pos].second;
        }
    }
};

#endif // MODHASHTABLE_H
