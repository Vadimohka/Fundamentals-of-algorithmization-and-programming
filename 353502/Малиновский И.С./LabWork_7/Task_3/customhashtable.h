#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include "hashtable.h"

class CustomHashTable : public HashTable {
public:
    CustomHashTable(int size = 20);

    void removeNegativeKeys();

private:
    void removeNegativeKeys(int index);
};

#endif // CUSTOMHASHTABLE_H
