#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <QVector>
#include <QStack>

class MyHashTable
{
public:
    MyHashTable(int initialCapacity);

    void generateRandomTable(int minKey, int maxKey, int numItems);
    void insert(int key, int value);
    void remove(int key);
    int find(int key) const;
    QVector<QVector<int>> display() const;
    void clear();

private:
    int hashFunction(int key) const;
    int getNextPrime(int n) const;
    bool isPrime(int n) const;
    int findMinKeyStack() const;

    QVector<QStack<int>> m_table;
    int m_capacity;
};

#endif // MYHASHTABLE_H
