#include "HashModTable.h"

#include <QString>

template<typename T>
int64_t HashModTable<T>::hashFunction(int64_t key)
{
    return key % _size;
}

template<typename T>
HashModTable<T>::HashModTable(size_t sizeTable)
    : node(new std::pair<int64_t, T>[sizeTable])
    , _size(sizeTable)
    , _amountСollisions(0)
    , _maxKey(0)
{
    for (size_t i = 0; i < sizeTable; ++i) {
        node[i].second = nullptr;
    }
}

template<typename T>
HashModTable<T>::~HashModTable()
{
    delete[] node;
}

template<typename T>
size_t HashModTable<T>::size() const
{
    return _size;
}

template<typename T>
size_t HashModTable<T>::amountСollisions() const
{
    return _amountСollisions;
}

template<typename T>
void HashModTable<T>::clear()
{
    for (size_t i = 0; i < _size; ++i) {
        node[i].second = nullptr;
    }
    _amountСollisions = 0;
}

template<typename T>
void HashModTable<T>::insert(int64_t key, T value)
{
    int64_t index = hashFunction(key);
    if (key > _maxKey) {
        _maxKey = key;
    }

    if (node[index].second != nullptr) {
        // Поиск свободной ячейки
        bool isInserted = false;
        for (size_t i = 0; i < _size; ++i) {
            if (node[i].second == nullptr) {
                node[i].first = key;
                node[i].second = value;
                isInserted = true;
                break;
            }
        }
        // Если свободная ячейка не найдена, выдать исключение
        if (!isInserted) {
            throw std::runtime_error("Хеш-таблица полна, вставка невозможна");
        }
        ++_amountСollisions;
    } else {
        node[index].first = key;
        node[index].second = value;
    }
}

template<typename T>
T HashModTable<T>::find(int64_t key)
{
    for (size_t i = 0; i < _size; ++i) {
        if (node[i].first == key) {
            return node[i].second;
        }
    }
    return nullptr;
}

template<typename T>
T HashModTable<T>::findMax()
{
    return find(_maxKey);
}

template class HashModTable<QString>;
