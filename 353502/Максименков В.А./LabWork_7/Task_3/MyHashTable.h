#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "HashTable.h"

class MyHashTable : public HashTable {
public:
    MyHashTable(int potentialSize) : HashTable(potentialSize) {}

    void deleteEvenKeys()
    {
        for (int i = 2; i <= MAX_KEY_SIZE; i += 2)
        {
            qDebug() << hashFunction(i);
            table[hashFunction(i)].clear();
        }
    }
};

#endif // SONTABLE_H
