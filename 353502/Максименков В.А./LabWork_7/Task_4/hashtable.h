#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QDebug>
#include <QPair>
#include <QVector>

const int MAX_KEY_SIZE = 100;

class HashTable
{
protected:
    int capacity = 1;
    int numberOfElements = 0;
    QVector<QPair<int, int>> table;
    int a = 0, b = 0; // числа для выбора hash-function (универсальное хэширование)
    int p = 0; // простое число, строго большее размера таблицы


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


    int getPrimeMoreThanNumber(int n)
    {
        do
        {
            ++n;
        }
        while (!numberIsPrime(n));

        return n;
    }


    int hashFunction(int key) // hash-function для чисел a, b, p;
    {
        return ((a * key + b) % p) % capacity;
    }


    int hashFunction(int key, int cnt) //  hash-function для борьбы с коллизиями (линейный метод)
    {                                   // вообще, она не используется, но во вставке элемента видна её суть
        return (hashFunction(key) + cnt) % capacity;
    }


    void rehash()
    {
        QVector<QPair<int, int>> oldTable = table;
        capacity = getPrimeMoreThanNumber(capacity * 2);
        p = getPrimeMoreThanNumber(capacity);
        table.resize(capacity);
        numberOfElements = 0;

        for (int i = 0; i < table.size(); ++i)
        {
            table[i].first = table[i].second = 0;
        }

        for (int i = 0; i < oldTable.size(); ++i)
        {
            if (oldTable[i].first != 0)
            {
                insertItem(oldTable[i].first, oldTable[i].second);
            }
        }
    }

public:
    HashTable(int size)
    {
        capacity = size;
        table.resize(capacity);
        p = getPrimeMoreThanNumber(capacity);
        srand(time(nullptr));
        a = 1 + rand() % (p-1);
        b = rand() % (p-1);

        for (int i = 0; i < capacity; ++i)
        {
            table[i] = QPair<int, int>(0, 0);
        }
    }


    void insertItem(int key, int data)
    {
        int index = hashFunction(key);
        int counter = 1;

        while (table[index].first != 0)
        {
            if (counter == capacity) return;
            index = (index + 1) % capacity;
            ++counter;
        }

        table[index].first = key;
        table[index].second = data;
        ++numberOfElements;

        if (numberOfElements > capacity * 0.7)
        {
            rehash();
        }
    }


    QVector<QPair<int, int>> displayHash()
    {
        QVector<QPair<int, int>> ans;

        for (int i = 0; i < capacity; i++)
        {
            ans.push_back(table[i]);
        }

        return ans;
    }
};

#endif // HASHTABLE_H
