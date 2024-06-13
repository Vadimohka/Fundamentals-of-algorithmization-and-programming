#ifndef HASHTABLETASK_H
#define HASHTABLETASK_H
#include<HashTable.h>
#include<QRandomGenerator>
#include<QDebug>
template<typename T>
class HashTableSolve : public HashTable<T>
{
public:

    HashTableSolve() {

    }

    ~HashTableSolve() override{

    }

    void createNewHashTable()
    {
        for(size_t i = 0 ; i < HashTable<T>::TABLE_SIZE; ++i)
        {
            int up = HashTable<T>::TABLE_SIZE;
            size_t element =  QRandomGenerator::global()->bounded(0, up);
            HashTable<T>::insert(element, element*element);
        }
    }

    void deleteOddIndex() {
        for (size_t i = 0; i < HashTable<T>::TABLE_SIZE; ++i) {
            if (i % 2 == 0 && !HashTable<T>::table[i].isEmpty()) {
                    HashTable<T>::remove(i, i * i);
            }
        }
    }


};
#endif // HASHTABLETASK_H
