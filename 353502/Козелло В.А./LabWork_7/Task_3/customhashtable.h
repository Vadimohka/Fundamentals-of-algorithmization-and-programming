#ifndef CUSTOM_HASHTABLE_H
#define CUSTOM_HASHTABLE_H
#include <QDebug>
#include <QVector>
#include "customstack.h"

class CustomHashTable
{
public:
    explicit CustomHashTable(int n)
        : size(n)
    {
        buckets.resize(size);
    }

    void clear();

    void addItem(int key, int value) { buckets[computeHash(key)].push(value); }

    void removeItem(int key) { buckets[computeHash(key)].pop(); }

    QVector<QVector<int>> getHashContents() const
    {
        QVector<QVector<int>> contents;
        for (int i = 0; i < size; ++i) {
            contents.append(buckets[i].toVector());
        }
        return contents;
    }

protected:
    int size = 1;
    QVector<CustomStack> buckets;

    int computeHash(int key) const { return key % size; }
};

#endif // CUSTOM_HASHTABLE_H
