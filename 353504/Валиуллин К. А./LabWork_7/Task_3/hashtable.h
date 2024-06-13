#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QVector>
#include <QStack>
#include <QString>

class HashTable {
public:
    HashTable(int size) : table(size) {}

    void push(int key, int value);
    bool pop(int key, int &value);
    void clear();

    QString print() const;

protected:
    virtual int hashFunction(int key) const;
    QVector<QStack<int>> table;

};

#endif // HASHTABLE_H
