#ifndef HASHMULTTABLE_H
#define HASHMULTTABLE_H

#include <QPair>
#include <cstddef>
#include <cstdint>

template<typename T>
class HashMultTable
{
private:
    std::pair<int64_t, T> *node;
    size_t _size;
    size_t _amountСollisions;
    int64_t _maxKey;

    int64_t hashFunction(int64_t key);

public:
    explicit HashMultTable(size_t sizeTable);
    ~HashMultTable();

    size_t size() const;
    size_t amountСollisions() const;
    void clear();
    void insert(int64_t key, T value);
    T find(int64_t key);
    T findMax();
};

#endif // HASHMULTTABLE_H
