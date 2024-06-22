#ifndef EXTENDEDHASHTABLE_H
#define EXTENDEDHASHTABLE_H

#include "hashtable.h"

class ExtendedHashTable : public HashTable
{
public:
    ExtendedHashTable(int size = 10);
    int findMaxKey();
    void insertRandomData();

private:
    QVector<QPair<int, QString>> getRandomData(int count);
};

#endif // EXTENDEDHASHTABLE_H

