#ifndef OPENHASHTABLE_H
#define OPENHASHTABLE_H

#include <QPair>
#include <cstddef>
#include <cstdint>
#include <QString>

template<typename T>
class OpenHashModTable
{
private:
    const double HASH_CONST = 0.6180339887;
    std::pair<int64_t, T> *node;
    size_t _size;
    size_t _amountСollisions{0};
    int64_t _maxKey{0};

    int64_t hashFunction(int64_t key)
    {
        return floor(_size * fmod(key * HASH_CONST, 1));
    }

public:


    explicit OpenHashModTable(size_t sizeTable)
        : node(new std::pair<int64_t, T>[sizeTable])
        , _size(sizeTable)
    {
        for (size_t i = 0; i < sizeTable; ++i) {
            node[i].second = nullptr;
        }
    }

    OpenHashModTable()
    {
        delete[] node;
    }

    size_t size() const
    {
        return _size;
    }

    size_t amountСollisions() const
    {
        return _amountСollisions;
    }

    void clear()
    {
        for (size_t i = 0; i < _size; ++i) {
            node[i].second = nullptr;
        }
        _amountСollisions = 0;
    }

    void insert(int64_t key, T value)
    {
        int64_t index = hashFunction(key);
        if (key > _maxKey) {
            _maxKey = key;
        }

        if (node[index].second != nullptr) {

            bool isInserted = false;
            for (size_t i = 0; i < _size; ++i) {
                if (node[i].second == nullptr) {
                    node[i].first = key;
                    node[i].second = value;
                    isInserted = true;
                    break;
                }
            }
            if (!isInserted) {
                throw std::runtime_error("Hash is full");
            }
            ++_amountСollisions;
        } else {
            node[index].first = key;
            node[index].second = value;
        }
    }

    T find(int64_t key)
    {
        for (size_t i = 0; i < _size; ++i) {
            if (node[i].first == key) {
                return node[i].second;
            }
        }
        return nullptr;
    }

    T findMax()
    {
        return find(_maxKey);
    }

QString print() {
    QString res = "";
    for(int i = 0; i < _size; ++i){
        if(node[i].first != -1){
            res += "index: " + QString::number(i) + " value: " + (node[i].second) + "\n";
        }
    }
    return res;
}

};

#endif // OPENHASHTABLE_H
