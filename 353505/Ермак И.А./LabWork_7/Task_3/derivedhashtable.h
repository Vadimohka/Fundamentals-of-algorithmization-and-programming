#ifndef DERIVEDHASHTABLE_H
#define DERIVEDHASHTABLE_H

#include "hashtable.h"

class DerivedHashTable : public HashTable {
public:
    DerivedHashTable(int size);
    int getStackWithMaxKey() const;
};

#endif // DERIVEDHASHTABLE_H

