#include "HashTable.h"

#include <QString>

template<typename T>
int64_t HashTable<T>::hashFunction(int64_t key)
{
    return key % _size;
}

template<typename T>
HashTable<T>::HashTable(size_t sizeTable)
    : table(new Stack<T>[sizeTable])
    , _size(sizeTable)
{}

template<typename T>
HashTable<T>::~HashTable()
{
    delete[] table;
}

template<typename T>
size_t HashTable<T>::size() const
{
    return _size;
}

template<typename T>
void HashTable<T>::insert(int64_t key, T value)
{
    int64_t index = hashFunction(key);
    table[index].push(key, value);
}

template<typename T>
T HashTable<T>::find(int64_t key)
{
    Stack<T> stack = table[hashFunction(key)];

    int64_t tempKey = 0;
    T tempValue;

    while (!stack.empty()) {
        stack.pop(tempKey, tempValue);
        if (tempKey == key) {
            return tempValue;
        }
    }

    return nullptr;
}

template class HashTable<QString>;
