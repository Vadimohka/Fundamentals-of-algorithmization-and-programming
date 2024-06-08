#ifndef STACKHASHTABLE_H
#define STACKHASHTABLE_H

#include "stack.h"
#include "QVector"

template <typename T> class StackHashTable
{
public:
    int size = 97;
    QVector<Stack<T>*> table;
    StackHashTable(){
        table.resize(size);
    }

    void put(QString key, T value){
        int pos = hashFunction(key);
        if(table.at(pos) == nullptr){
            table[pos] = new Stack<T>();
        }
        table.at(pos)->put(value);
    }

    T get(QString key){
        int pos = hashFunction(key);
        if(table.at(pos) == nullptr){
            return 0;
        }
        else{
            return table.at(pos)->pop();
        }
    }

    int hashFunction(QString str){
        int result = 13;
        for(int i = 0; i < str.length(); i++){
            result = result * size + str.at(i).digitValue();
        }
        return result % size;
    }
};

#endif // STACKHASHTABLE_H
