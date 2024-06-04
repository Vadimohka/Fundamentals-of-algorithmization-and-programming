#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HASHTABLE_H

#define SIZE 16

#include <cstdio>
#include <QDebug>
#include <QRandomGenerator>

template <typename T>
class HashTable
{
public:
    HashTable();
    HashTable(size_t n);
    ~HashTable();
    void insert(int key);
    void remove(int key);
    bool search(int key);
    void print();
    int getHash(int key);
    int getUniversal(int key);
    int getCount();
    QString toString();
    size_t getSize() {return size;}
    float getLoadFactor()
    {
        return loadFactor; }
private:
    T** table;
    size_t size;
    float loadFactor{};
    int count{};
    int collisions{};
    int hash(int key);
};

template <typename T>
HashTable<T>::HashTable() : HashTable(SIZE)
{}

template <typename T>
HashTable<T>::HashTable(size_t n) : size(n)
{
    table = new T*[size];
    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }
}

template <typename T>
HashTable<T>::~HashTable()
{
    for (int i = 0; i < size; ++i)
    {
        if (table[i] != nullptr)
        {
            delete table[i];
        }
    }
    delete[] table;
}

template <typename T>
void HashTable<T>::insert(int key)
{
    int index = hash(key);
    if(table[index] != nullptr)
    while (table[index] != nullptr)
    {
        index = (index + 1) % size;
    }
    table[index] = new T(key);
    count++;
    loadFactor = static_cast<float>(count) / size;
}

template <typename T>
void HashTable<T>::remove(int key)
{
    int index = hash(key);

    while (table[index] != nullptr && *table[index] != key)
    {
        index = (index + 1) % size;
    }
    if (table[index] == nullptr)
    {
        return;
    }
    delete table[index];
    table[index] = nullptr;
    count--;
    loadFactor = static_cast<float>(count) / size;
}

template <typename T>
bool HashTable<T>::search(int key)
{
    int index = hash(key);
    while (table[index] != nullptr)
    {
        if(*table[index] == key)
        {
            return true;
        }
        index = (index + 1) % size;
    }
    return false;
}

template <typename T>
void HashTable<T>::print()
{
    for (int i = 0; i < size; ++i)
    {
        qDebug() << i << ": " << table[i];
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
    return hash(key);
}

template <typename T>
int HashTable<T>::getCount()
{
    return count;
}

template <typename T>
QString HashTable<T>::toString()
{
    QString str;
    for (int i = 0; i < size; ++i)
    {
        str += QString::number(i) + ": " + QString::number(*table[i]) + "\n";
    }
    return str;
}

template <typename T>
int HashTable<T>::getUniversal(int key)
{
    //  ((a*k + b)mod(p))mod(m)
    //  a = {1...p-1}; b = {0...p-1} // p - simple number > size

    int a = 31415, b = 27183;
    return ((a * key + b) % 16908799) % size;
}
#endif // HASHTABLE_H
