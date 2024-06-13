#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"


class MyHashTable : public HashTable
{
private:

public:
    using HashTable::HashTable;
    void createRandomHashTable();
    QVector<int> findMinKey();
};

#endif // MYHASHTABLE_H
