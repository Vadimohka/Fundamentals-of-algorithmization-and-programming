#ifndef HASHTABLEAVG_H
#define HASHTABLEAVG_H

#include "hashtable.h"
#include <QListWidget>

template<typename T>
class HashTableAvg : public HashTable<T>
{
private:
    int64_t _sumKeys;
    size_t _countElements;

public:
    explicit HashTableAvg(size_t sizeTable);
    ~HashTableAvg() override = default;

    void insert(int64_t key, T value) override;
    int64_t getAvgKey();
    size_t getCountAboveAvg();
    void inputToTableWidget(QListWidget& widget);
};



#endif // HASHTABLEAVG_H
