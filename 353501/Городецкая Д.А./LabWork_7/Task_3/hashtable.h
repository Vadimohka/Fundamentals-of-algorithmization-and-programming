#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "notmyhashtable.h"
class mht: public HashTable
{
public:
    mht(int size):HashTable(size)
    {

    }
    void solveTask()
    {
        for(int i=0;i<mod;i+=2)
        {
            table[i].clear();
        }
    }
};
#endif // HASHTABLE_H
