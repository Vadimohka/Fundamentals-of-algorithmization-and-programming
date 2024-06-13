#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <QList>
#include <QStack>
#include <QDebug>
#include <QPair>

class Hash_table
{
protected:
    int capacity;
    int length;
    QList<QPair<int,QStack<int>>> table;

    int hash_function(int key);


    int hash(int key, int i);
    int get_next_prime(int number);

    bool is_prime(int number);

public:
    Hash_table(int capacity);

    void insert(int key, int value);
    void remove(int key);

    void resize(int size);
    void clear();

    int size();

    int get_element_from_index(int index);
    int get_key_from_index(int index);

};

#endif // HASH_TABLE_H
