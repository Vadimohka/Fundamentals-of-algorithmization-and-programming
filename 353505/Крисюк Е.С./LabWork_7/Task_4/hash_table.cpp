#include "hash_table.h"

Hash_table::Hash_table(int size) {

    capacity = get_next_prime(size);

    length = 0;
    table.resize(capacity);
}

int Hash_table::get_next_prime(int number){

    while(!is_prime(number)){
        ++number;
    }

    return number;
}

bool Hash_table::is_prime(int number){

    if(number <= 1){
        return false;
    }

    for(int i = 2; i <= sqrt(number); ++i){
        if(number % i == 0){
            return false;
        }
    }
    return true;

}

int Hash_table::hash(int key, int i) {

    int h1 = key % capacity;
    int h2 = 1 + (key % (capacity + 1));

    return (h1 + i * h2) % capacity;
}

void Hash_table::insert(int key, int value){

    int index = hash(key,0);

    while(!table[index].second.isEmpty()){
        index = hash(key, index);

        qDebug() << index;
    }

    qDebug() << "============================";

    ++length;

    if(length > capacity * 0.4){
        resize(int(1.6 * capacity));
    }

    table[index].second.push(value);

    table[index].first = key;
}

void Hash_table::remove(int key){
    int index = hash(key,0);


    while(!table[index].second.isEmpty()){
        table[index].second.clear();

        index = hash(key, index);
    }

    --length;
}


void Hash_table::resize(int number){
    capacity = get_next_prime(number);
    table.resize(capacity);
}


void Hash_table::clear() {
    for(int i = 0; i < table.length(); ++i){
        table[i].second.clear();
    }
}

int Hash_table::size(){
    return capacity;
}

int Hash_table::get_element_from_index(int index){
    index = hash(index,0);

    if(!table[index].second.isEmpty()){
        return table[index].second.top();
    }

    return -1;
}

int Hash_table::get_key_from_index(int index){
    return table[index].first;
}
