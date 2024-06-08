

#ifndef TASK3_TASKHASH_H
#define TASK3_TASKHASH_H

#include <ctime>
#include <cstdlib>
#include <string>
#include "hashtable.h"

class TaskHash : public HashTable {
    std::vector<int> numbers;

public:
    TaskHash()
    {
        HashTable();
        srand(time(0));
        for(int i = 0; i < 1000; i ++)
        {
            int value = rand() % 1000000 + 1;
            InsertValue(value);
            numbers.push_back(value);
        }
    }

    int FindMaxStack()
    {
        for(int i = capacity - 1; i >= 0; i --)
        {
            if(table[i].size() != 0)
                return i + 1;
        }
        return -1;
    }

    std::vector<std::pair<int, std::string> > GetHashTable()
    {
        std::vector<std::pair<int, std::string > > ret;
        for(int i = 0; i < capacity; i ++)
        {
            if(table[i].size() != 0)
            {
                ret.push_back({i, table[i].GetString()});
            }
        }
        return ret;
    }

};


#endif //TASK3_TASKHASH_H
