#ifndef TSKTABLE_H
#define TSKTABLE_H
#pragma once
#include "HashTable.h"

class TskTable : public HashTable
{
public:
    TskTable(int V)
        : HashTable(V)
    {}

    int findMinStack()
    {
        int minIndex = -1;
        long long minValue = 1000000000000000000;
        for (int i = 0; i < tableSize; ++i) {
            for (int value : table[i].toQVectorKey()) {
                if (value < minValue) {
                    minValue = value;
                    minIndex = i;
                }
            }
        }
        return minIndex;
    }
};

#endif // SONTABLE_H
