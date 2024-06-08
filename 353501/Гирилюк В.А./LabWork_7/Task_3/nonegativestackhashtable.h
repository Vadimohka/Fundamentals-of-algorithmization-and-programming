#ifndef NONEGATIVESTACKHASHTABLE_H
#define NONEGATIVESTACKHASHTABLE_H

#include "stackhashtable.h"

class NoNegativeStackHashTable: public StackHashTable<int>
{
public:
    NoNegativeStackHashTable();

    void DeleteAllNegative();

    QString stackToQString(int index);
};

#endif // NONEGATIVESTACKHASHTABLE_H
