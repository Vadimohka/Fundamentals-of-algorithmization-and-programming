#include "HashMultTable.h"

#include <QString>

constexpr double HASH_CONST = 0.6180339887;

template<typename T>
int64_t HashMultTable<T>::hashFunction(int64_t key)
{
    return floor(_size * fmod(key * HASH_CONST, 1));
}

template<typename T>
HashMultTable<T>::HashMultTable(size_t sizeTable)
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
HashMultTable<T>::~HashMultTable()
{
    delete[] node;
}

template<typename T>
size_t HashMultTable<T>::size() const
{
    return _size;
}

template<typename T>
size_t HashMultTable<T>::amountСollisions() const
{
    return _amountСollisions;
}

template<typename T>
void HashMultTable<T>::clear()
{
    for (size_t i = 0; i < _size; ++i) {
        node[i].second = nullptr;
    }
    _amountСollisions = 0;
}

template<typename T>
void HashMultTable<T>::insert(int64_t key, T value)
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
T HashMultTable<T>::find(int64_t key)
{
    for (size_t i = 0; i < _size; ++i) {
        if (node[i].first == key) {
            return node[i].second;
        }
    }
    return nullptr;
}

template<typename T>
T HashMultTable<T>::findMax()
{
    return find(_maxKey);
}

template class HashMultTable<QString>;
