#ifndef ANOTHERTABLE_H
#define ANOTHERTABLE_H

#include "customhashtable.h"

class CustomSonTable : public CustomHashTable
{
public:
    explicit CustomSonTable(int n)
        : CustomHashTable(n)
    {}

    void removeEvenKeys()
    {
        for (int i = 0; i < size; ++i) {
            if (i % 2 == 0) {
                buckets[i].clear();
            }
        }
    }
};

#endif // ANOTHERTABLE_H
