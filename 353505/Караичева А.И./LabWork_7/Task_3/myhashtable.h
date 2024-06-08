#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"
#include <QString>
#include <climits>
#include <qframe.h>
#include <qnamespace.h>
#include <qtablewidget.h>
#include <qcontainerfwd.h>

class MyHashTable: public HashTable<QString> {
public:
    MyHashTable();
    ~MyHashTable();

    void randomize();

    void fillEnties(QTableWidget *entries);

    long findTotalLen();
};
#endif // MYHASHTABLE_H
