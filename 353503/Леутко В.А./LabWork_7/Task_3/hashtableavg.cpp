#include "hashtableavg.h"

#include <QString>

template<typename T>
HashTableAvg<T>::HashTableAvg(size_t sizeTable)
    : HashTable<T>(sizeTable)
    , _sumKeys(0)
    , _countElements(0)
{
}

template<typename T>
void HashTableAvg<T>::insert(int64_t key, T value)
{
    HashTable<T>::insert(key, value);
    _sumKeys += key;
    ++_countElements;
}

template<typename T>
int64_t HashTableAvg<T>::getAvgKey()
{
    return _sumKeys / _countElements;
}

template<typename T>
size_t HashTableAvg<T>::getCountAboveAvg()
{
    size_t countAboveAvg = 0;
    int64_t avgKey = getAvgKey();

    for (size_t i = 0; i < HashTable<T>::size(); ++i)
    {
        Stack<T>& stack = HashTable<T>::table[i];
        while (!stack.empty())
        {
            int64_t key;
            T value;
            stack.pop(key, value);
            if (key > avgKey)
            {
                ++countAboveAvg;
            }
        }
    }

    return countAboveAvg;
}

template<typename T>
void HashTableAvg<T>::inputToTableWidget(QListWidget& widget)
{
    Stack<QString> tempStack;
    QString tempString;
    int64_t tempKey = 0;
    T tempValue;

    for (size_t i = 0; i < HashTable<T>::size(); ++i) {
        tempString = QString::number(i) + ". ";
        tempStack = HashTable<T>::table[i];

        while (!tempStack.empty()) {
            tempStack.pop(tempKey, tempValue);
            tempString += "Key: " + QString::number(tempKey) + " Value: " + tempValue + " -> ";
        }
        widget.addItem(tempString);
    }
}

template class HashTableAvg<QString>;
