#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include "hashtable.h"

class hashtablewithnonegativenumbers : public HashTable {
public:
    hashtablewithnonegativenumbers(int size) : HashTable(size) {}
    void removeNegativeKeys();
};

#endif // CUSTOMHASHTABLE_H
