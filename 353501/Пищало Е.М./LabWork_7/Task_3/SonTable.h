#ifndef SONTABLE_H
#define SONTABLE_H
#pragma once
#include "hashtable.h"

class SonTable : public HashTable {
public:
    SonTable(int V) : HashTable(V){}

    void deleteEvenKeys() {
        for (int i = 0; i < capacity; ++i)
            if (!(i % 2)) table[i].clear();
    }
};

#endif // SONTABLE_H
