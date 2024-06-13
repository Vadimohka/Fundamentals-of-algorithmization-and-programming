#include "HashTable.h"

#include <QString>

template<typename T>
HashTableMax<T>::HashTableMax(size_t sizeTable)
    : HashTable<T>(sizeTable)
    , _maxKey(0)
{}

template<typename T>
HashTableMax<T>::~HashTableMax() = default;

template<typename T>
void HashTableMax<T>::insert(int64_t key, T value)
{
    HashTable<T>::insert(key, value);
    if (key > _maxKey) {
        _maxKey = key;
    }
}

template<typename T>
int64_t HashTableMax<T>::getMaxKey()
{
    return _maxKey;
}

template<typename T>
T HashTableMax<T>::findMax()
{
    return HashTable<T>::find(_maxKey);
}

template<typename T>
void HashTableMax<T>::inputToTableWidget(QListWidget &widget)
{
    Stack<QString> tempStack;
    QString tempString;
    int64_t tempKey = 0;
    T tempValue;

    for (size_t i = 0; i < HashTable<T>::size(); ++i) {
        tempString = "[" + QString::number(i) + "] - ";
        tempStack = HashTable<T>::table[i];

        tempStack.pop(tempKey, tempValue);
        tempString += "Key: " + QString::number(tempKey) + " Value: " + tempValue;
        widget.addItem(tempString);
    }
}

template class HashTableMax<QString>;
