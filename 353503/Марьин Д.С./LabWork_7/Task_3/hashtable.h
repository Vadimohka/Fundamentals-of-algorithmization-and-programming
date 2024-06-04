#ifndef HASHTABLE_H
#define HASHTABLE_H

#define SIZE 16
#define MaxLoad 0.75

#include <cstdio>
#include <QDebug>
#include "stack.h"

template <typename T>
class HashTable
{
public:
    HashTable();
    explicit HashTable(size_t n);
    ~HashTable();
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void resize();
    Stack<T>* getTable() { return table; }
    void print();
    std::string toString();
    int getHash(int key);
    size_t getSize() {return size;}
    float getLoadFactor()
    {
        return loadFactor; }
private:
    Stack<T>* table;
    size_t size;
    float loadFactor;
    int count;
    int hash(int key);
};

template <typename T>
HashTable<T>::HashTable()
{
    table = new Stack<T>[SIZE];
    size = SIZE;
}

template <typename T>
HashTable<T>::HashTable(size_t n)
{
    table = new Stack<T>[n];
    size = n;
}

template <typename T>
HashTable<T>::~HashTable()
{
    delete[] table;
}

template <typename T>
void HashTable<T>::insert(int key)
{
    int index = hash(key);
    table[index].push(key);
    count++;
    loadFactor = static_cast<float>(count) / size;
    if (loadFactor > MaxLoad)
    {
        resize();
        loadFactor = static_cast<float>(count) / size;
    }
}

template <typename T>
void HashTable<T>::remove(int key)
{
    int index = hash(key);
    Stack<T> temp;
    while (!table[index].isEmpty())
    {
        T data = table[index].pop();
        if (data != key)
        {
            temp.push(data);
        }
    }
    while (!temp.isEmpty())
    {
        table[index].push(temp.pop());
    }
    count--;
    loadFactor = static_cast<float>(count) / size;
}

template <typename T>
bool HashTable<T>::search(int key)
{
    int index = hash(key);
    Stack<T> temp;
    bool found = false;
    while (!table[index].isEmpty())
    {
        T data = table[index].pop();
        if (data == key)
        {
            found = true;
        }
        temp.push(data);
    }
    while (!temp.isEmpty())
    {
        table[index].push(temp.pop());
    }
    return found;
}

template <typename T>
void HashTable<T>::print()
{
    for (int i = 0; i < size; ++i)
    {
        qDebug() << i << ": ";
        table[i].print();
    }
}

template <typename T>
int HashTable<T>::hash(int key)
{
    return key % size;
}

template <typename T>
int HashTable<T>::getHash(int key)
{
    return hash();
}

template <typename T>
std::string HashTable<T>::toString()
{
    std::string str;
    for (int i = 0; i < size; ++i)
    {
        str += std::to_string(i) + ": " + table[i].toString() + "\n\n";
    }
    return str;
}

template <typename T>
void HashTable<T>::resize()
{
    size_t newSize = size * 2;
    Stack<T>* newTable = new Stack<T>[newSize];
    for (int i = 0; i < size; ++i)
    {
        while (!table[i].isEmpty())
        {
            T data = table[i].pop();
            int index = data % newSize;
            newTable[index].push(data);
        }
    }
    delete[] table;
    table = newTable;
    size = newSize;
    loadFactor = static_cast<float>(count) / size;
}
#endif // HASHTABLE_H
