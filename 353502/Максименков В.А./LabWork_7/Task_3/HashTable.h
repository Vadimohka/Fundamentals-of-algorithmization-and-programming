#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QVector>
#include "Stack.h"

const int MAX_KEY_SIZE = 100;

class HashTable
{
protected:
    int capacity = 1;
    int currentNumberOfElements = 0;
    QVector<Stack> table;

    bool numberIsPrime(int n)
    {
        if (n == 1) return false;
        if (n == 2 || n == 3) return true;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }


    int reconstructTableSize(int n)
    {
        while (!numberIsPrime(n))
        {
            ++n;
        }
        return n;
    }


    int hashFunction(int key) // простейшая hash-function
    {
        return key % capacity;
    }

public:
    HashTable(int potentialSize)
    {
        capacity = reconstructTableSize(potentialSize);
        table.resize(capacity);
    }


    void insertItem(int key, int data)
    {
        table[hashFunction(key)].push(data);
        ++currentNumberOfElements;

        /*if (currentNumberOfElements > capacity * 0,7)
        {
            QVector<Stack> newTable;
            newTable.resize(capacity * 2);
            for (int i = 0; i < capacity)
        }*/
    }


    void deleteItem(int key)
    {
        table[hashFunction(key)].pop();
    }


    QVector<QVector<int>> displayHash()
    {
        QVector<QVector<int>> result;

        for (int i = 0; i < capacity; i++)
        {
            result.append(table[i].toQVector());
        }

        return result;
    }

    void clear()
    {
        for (int i = 0; i < table.size(); ++i)
        {
            table[i].clear();
        }
    }
};

#endif // HASHTABLE_H
