#include "hashtable.h"
#include <cstddef>

template<typename T>
int HashTable<T>::hashFunction(int key) const
{
    return ((key % size) * (key % size)) % size;
}

template<typename T>
HashTable<T>::HashTable(int size)
{
    table = new Stack<Item<T>>[size];
    this->size = size;
}

template<typename T>
HashTable<T>::~HashTable()
{

}

template<typename T>
void HashTable<T>::insert(int key, T value)
{
    int index = hashFunction(key);
    if(get(key) == "error!@#$%^&*()") table[index].push(Item(key, value));
    else
    {
        Stack<Item<T>> tempStack;

        while (!table[index].isEmpty())
        {
            Item stackItem = table[index].pop();
            tempStack.push((stackItem.key == key) ? (Item<T>(key, value)) : stackItem);

            if (stackItem.key == key)
            {
                break;
            }
        }

        while (!tempStack.isEmpty()) {
            table[index].push(tempStack.pop());
        }
    }
}

template<typename T>
T HashTable<T>::get(int key)
{
    T foundedValue;
    bool isFounded = false;

    int index = hashFunction(key);
    Stack<Item<T>> tempStack;

    while (!table[index].isEmpty()) {
        Item stackItem = table[index].pop();
        tempStack.push(stackItem);
        if (stackItem.key == key) {
            foundedValue = stackItem.value;
            isFounded = true;
            break;
        }
    }

    while (!tempStack.isEmpty()) {
        table[index].push(tempStack.pop());
    }

    return isFounded ? foundedValue : "error!@#$%^&*()";
}


template<typename T>
void HashTable<T>::remove(int key)
{
    int index = hashFunction(key);
    Stack<Item<T>> tempStack;

    while (!table[index].isEmpty()) {
        Item stackItem = table[index].pop();

        if (stackItem.key != key) {
            tempStack.push(stackItem);
        }
    }

    while (!tempStack.isEmpty()) {
        table[index].push(tempStack.pop());
    }

}
