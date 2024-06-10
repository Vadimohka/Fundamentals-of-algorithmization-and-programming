#ifndef HASHTABLE_H
#define HASHTABLE_H

constexpr short SIZE = 16;
constexpr float MAX_LOAD = 0.75;

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
    size_t getSize() { return size; }
    std::string toString();
    int getHash(int key);
    void checkLoadFactor();
    float getLoadFactor()
    {
        return loadFactor;
    }
private:
    Stack<T>* table;
    size_t size;
    float loadFactor;
    int count;
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
    table[getHash(key)].push(key);
    count++;
    checkLoadFactor();
}

template <typename T>
void HashTable<T>::remove(int key)
{
    int index = getHash(key);
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
    int index = getHash(key);
    Stack<T> temp;
    while (!table[index].isEmpty())
    {
        T data = table[index].pop();
        if (data == key)
        {
            temp.push(data);
            while (!temp.isEmpty())
            {
                table[index].push(temp.pop());
            }
            return true;
        }
        temp.push(data);
    }
    while (!temp.isEmpty())
    {
        table[index].push(temp.pop());
    }
    return false;
}

template <typename T>
int HashTable<T>::getHash(int key)
{
    return key % size;
}

template<typename T>
void HashTable<T>::checkLoadFactor()
{
    loadFactor = static_cast<float>(count) / size;
    if (loadFactor > MAX_LOAD)
    {
        resize();
        loadFactor = static_cast<float>(count) / size;
    }
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
            int key = table[i].pop();
            newTable[key % newSize].push(key);
        }
    }
    delete[] table;
    table = newTable;
    size = newSize;
}

#endif // HASHTABLE_H
