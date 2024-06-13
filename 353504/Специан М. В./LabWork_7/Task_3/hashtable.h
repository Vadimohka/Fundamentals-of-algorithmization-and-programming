#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <Stack.h>

class HashTable
{
protected:
    long long size;

    long long hash(long long key)
    {
        return (50 + key) % size;
    }

    QVector<Stack> table;

public:
    HashTable(long long size)
    {
        this->size = size;
        table.resize(size);
    }

    void addItem(long long key, int value)
    {
        long long index = hash(key);
        table[index].push(value);
    }

    void removeItem(long long key)
    {
        long long index = hash(key);
        if (!table[index].isEmpty())
        {
            table[index].pop();
        }
    }

    QVector<QVector<int>> toVector()
    {
        QVector<QVector<int>> result;
        for (int i = 0; i < size; ++i)
        {
            result.push_back(table[i].toVector());
        }
        return result;
    }

    void clear()
    {
        for (auto & e : table)
        {
            e.clear();
        }
    }
};

#endif // HASHTABLE_H
