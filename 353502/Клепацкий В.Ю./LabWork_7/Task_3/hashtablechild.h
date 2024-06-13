#ifndef HASHTABLECHILD_H
#define HASHTABLECHILD_H

#include <QListWidget>
#include "hashtable.cpp"
#include "hashtable.h"

template<typename T>
class HashTableChild : public HashTable<T>
{
public:
    HashTableChild(int size);

    void print(QListWidget *listWidget);

    void deleteAllEvenKeys();

    void clear();
};

#endif // HASHTABLECHILD_H
