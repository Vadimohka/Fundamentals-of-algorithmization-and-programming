#ifndef HASHTABLEEXTENSION_H
#define HASHTABLEEXTENSION_H

#include <hashtable.h>
#include <QRandomGenerator>

class HashTableExtension : public HashTable
{
public:
    using HashTable::HashTable;
    void createRandomHashTable();
    QPair<HashTableExtension*, HashTableExtension*> divide();
};

#endif // HASHTABLEEXTENSION_H
