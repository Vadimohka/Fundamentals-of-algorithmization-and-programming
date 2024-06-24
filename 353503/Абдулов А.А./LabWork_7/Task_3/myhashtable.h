#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"


class MyHashTable : public HashTable
{
private:

public:
    using HashTable::HashTable;
    void createRandomHashTable(int count);
    QString findMaxKey();
};

#endif // MYHASHTABLE_H
