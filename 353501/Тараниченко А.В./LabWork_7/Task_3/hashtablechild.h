#ifndef HASHTABLECHILD_H
#define HASHTABLECHILD_H

#include "hashtable.h"
#include "hashtable.cpp"
#include <QListWidget>

template <typename T>
class HashTableChild : public HashTable<T>
{
public:
    HashTableChild(int size);

    void print(QListWidget* listWidget);

    void deleteAllEvenKeys();

    void clear();

};

#endif // HASHTABLECHILD_H
