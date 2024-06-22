#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include <QVector>
#include <QPair>

class HashTable
{
public:
    HashTable(int size = 10);
    void insert(int key, const QString& value);
    QString find(int key);
    void printTable();

    QVector<QPair<int, QString>> *table;
    int size;
    int hash(int key);
};

#endif // HASHTABLE_H

