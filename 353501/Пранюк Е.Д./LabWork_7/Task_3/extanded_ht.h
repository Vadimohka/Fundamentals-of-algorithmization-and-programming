#ifndef EXTANDED_HT_H
#define EXTANDED_HT_H

#include "hashtable.h"

template <typename T>
class Extanded_HT : public HashTable<T>
{
public:
    Extanded_HT() : HashTable<T>() {}
    explicit Extanded_HT(size_t n) : HashTable<T>(n) {}
    T findMinKey();
};

template<typename T>
T Extanded_HT<T>::findMinKey()
{
    T min;
    bool was = false;
    for(int i = 0; i < this->getSize(); ++i)
    {
        Stack<T> temp;
        while (!this->getTable()[i].isEmpty())
        {
            T data = this->getTable()[i].pop();
            if(!was || min > data)
            {
                min = data;
                was = true;
            }
            temp.push(data);
        }
        while (!temp.isEmpty())
        {
            this->getTable()[i].push(temp.pop());
        }
    }
    return min;
}

#endif // EXTANDED_HT_H
