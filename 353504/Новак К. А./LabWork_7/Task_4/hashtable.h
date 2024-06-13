#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
#include <QString>
#include <QListWidget>

const size_t Size = 16;

template<typename T>
class HashTable
{
private:
    T** table;
    size_t _size;
    float _loadFactor{};

    int _count{};
    int _collisions{};
    int hashFunction(int key);
public:
    HashTable();
    HashTable(size_t n);
    ~HashTable();

    void insert(int key);
    void remove(int key);
    size_t find(int key);

    int getHash(int key);
    int getCount();
    size_t getSize() {return _size;}
    float getLoadFactor();

    QString print();
};

template <typename T>
HashTable<T>::HashTable() : HashTable(Size)
{}

template <typename T>
HashTable<T>::HashTable(size_t size) : _size(size)
{
    table = new T*[size];

    for(int i = 0; i < size; ++i){
        table[i] = nullptr;
    }
}

template <typename T>
HashTable<T>::~HashTable()
{
    for(int i = 0; i < _size; ++i){
        delete table[i];
    }

    delete table;
}

template<typename T>
void HashTable<T>::insert(int key){
    int index = hashFunction(key);
    int counter = 0;
    if(table[index] != nullptr){
        while((table[index] != nullptr) || counter > _size){
            index = (index + 1) % _size;
            ++counter;
        }
    }
    if(counter < _size){
        table[index] = new T(key);
        _count++;
    }
    _loadFactor = static_cast<float>(_count) / _size;

}

template <typename T>
void HashTable<T>::remove(int key)
{
    int index = hashFunction(key);

    while (table[index] != nullptr && *table[index] != key)
    {
        index = (index + 1) % _size;
    }
    if (table[index] == nullptr)
    {
        return;
    }
    delete table[index];

    table[index] = nullptr;
    _count--;
    _loadFactor = static_cast<float>(_count) / _size;
}

template <typename T>
size_t HashTable<T>::find(int key)
{
    int index = hashFunction(key);
    while (table[index] != nullptr)
    {
        if(*table[index] == key)
        {
            return index;
        }
        index = (index + 1) % _size;
    }
    return -1;
}


template <typename T>
QString HashTable<T>::print()
{
    QString Line = "";
    for (int i = 0; i < _size; ++i)
    {
        if(table[i] == nullptr){
            Line += QString::number(i) + ":\n";
        }
        else{Line += QString::number(i) + ": " + QString::number(*table[i]) + "\n";
        }
    }

    return Line;
}

template <typename T>
int HashTable<T>::hashFunction(int key)
{
    return key % _size;
}

template <typename T>
int HashTable<T>::getHash(int key)
{
    return hashFunction(key);
}




































#endif // HASHTABLE_H
