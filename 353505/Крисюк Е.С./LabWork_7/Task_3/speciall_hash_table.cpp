#include "speciall_hash_table.h"


void Speciall_hash_table::generate_random_table(int min_key, int max_key, int count_of_elements) {
    int key, value;

    for(int i = 0; i < count_of_elements; ++i){

        this -> resize(count_of_elements);

        key = QRandomGenerator::global() -> bounded(min_key, max_key);
        value = QRandomGenerator::global() -> bounded(0,100);

        this -> insert(key, value);
    }
}

int Speciall_hash_table::find_stack_with_min_key(){


    for(int i = 0; i < capacity; ++i){
        if(!table[i].isEmpty()){
            return i;

        }
    }

    return -1;
}
