#include "hashTable.h"
#include <QRandomGenerator>

class myHash : public HashTable{
    public:
        myHash(int V) : HashTable(V) {};
        void generateRandomHashTable(int size);
        int findStackWithMinKey();
};