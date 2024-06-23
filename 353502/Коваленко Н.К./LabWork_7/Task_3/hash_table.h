#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "stack.h"
#include <QList>

class Hash_table
{
protected:
    int capacity;
    QList<Stack> table;

    int hash_function(int key);


    int hash(int number);
    int get_next_prime(int number);

    bool is_prime(int number);

public:
    Hash_table(int capacity);

    void insert(int key, int value);
    void remove(int key);

    void resize(int size);
    void clear();

    QList<int>* Get_stack_from_index(int index);

    int size();

};

#endif // HASH_TABLE_H
