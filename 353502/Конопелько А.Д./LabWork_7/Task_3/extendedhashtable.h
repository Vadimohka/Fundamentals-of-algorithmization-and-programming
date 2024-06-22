#ifndef EXTENDEDHASHTABLE_H
#define EXTENDEDHASHTABLE_H

#include "hashtable.h"

class ExtendedHashTable : public HashTable {
public:
    ExtendedHashTable(int size);

    int countKeysAboveAverage() const;

private:
    float calculateAverage() const;
};

#endif // EXTENDEDHASHTABLE_H
