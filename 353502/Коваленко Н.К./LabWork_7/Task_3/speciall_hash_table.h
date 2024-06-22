#ifndef SPECIALL_HASH_TABLE_H
#define SPECIALL_HASH_TABLE_H

#include "hash_table.h"
#include <QRandomGenerator>

class Speciall_hash_table : public Hash_table
{

public:
    using Hash_table::Hash_table;

    int find_stack_with_min_key();

    void generate_random_table(int min_key, int max_key, int count_of_elements);
};

#endif // SPECIALL_HASH_TABLE_H
