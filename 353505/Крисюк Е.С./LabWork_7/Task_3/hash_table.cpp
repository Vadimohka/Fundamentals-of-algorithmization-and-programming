#include "hash_table.h"

Hash_table::Hash_table(int size) {

    capacity = get_next_prime(size);

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

int Hash_table::hash(int number) {
    return number % capacity;
}

void Hash_table::insert(int key, int value){
    int index = hash(key);
    table[index].push(value);
}

void Hash_table::remove(int key){
    int index = hash(key);

    if(!table[index].isEmpty()){
        table[index].pop();
    }
}


void Hash_table::resize(int number){
    capacity = get_next_prime(number);
    table.resize(capacity);

}

void Hash_table::clear() {
    for(int i = 0; i < table.length(); ++i){
        table[i].clear();
    }
}

QList<int> *Hash_table::Get_stack_from_index(int index){
    if(index < 0 && index > table.length()){
        throw "index out of range";
    }

    QList<int>* temp = table[index].Stack_to_list();

    return temp;
}

int Hash_table::size(){
    return capacity;
}
