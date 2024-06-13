#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <stack.h>
#include <QRandomGenerator>

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
        table[index].push({key, value});
    }

    void removeItem(long long key)
    {
        long long index = hash(key);
        if (!table[index].isEmpty())
        {
            table[index].pop();
        }
    }

    QVector<QVector<Pair>> toVector()
    {
        QVector<QVector<Pair>> result;
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
    QPair<HashTable*, HashTable*> divide()
    {
        HashTable* pos = new HashTable(size);
        HashTable* neg = new HashTable(size);

        for (int i = -50; i < 0; ++i)
        {
            auto vec = table[hash(i)].toVector();
            for (auto& e : vec)
            {
                neg->addItem(i, e.value);
            }
        }

        for (int i = 0; i <= 50; ++i)
        {
            auto vec = table[hash(i)].toVector();
            for (auto& e : vec)
            {
                pos->addItem(i, e.value);
            }
        }
        return qMakePair(neg, pos);
    }

    void createRandomHashTable()
    {
        int n = QRandomGenerator::global()->bounded(0, size);
        for (int i = 0; i < n; ++i)
        {
            addItem(QRandomGenerator::global()->bounded(-50, 50), QRandomGenerator::global()->bounded(0, 100));
        }
    }
};

#endif // HASHTABLE_H
