#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
template<typename T>
class Stack
{
private:
    struct Node
    {
        Node *next;
        int key;
        T value;
        Node(int key, T value)
            : key(key)
            , value(value)
            , next(nullptr)
        {}
    };

    Node *top;
    int sz;

public:
    Stack()
        : top(nullptr){};

    ~Stack() { clear(); }

    Node *Top() { return top; }

    void push(int key, T value)
    {
        Node *temp = new Node(key, value);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (top == nullptr) {
            return;
        }
        Node *temp = top;
        top = top->next;
        sz--;
        delete temp;
    }

    void clear()
    {
        while (top) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        sz = 0;
    }

    int size() { return sz; }

    bool empty() { return sz == 0; }
};

template<typename T>
class HashTable
{
protected:
    Stack<T> *table;

private:
    int _size;

    int hashFunction(int key) { return key % _size; }

public:
    HashTable(int sizeTable)
        : table(new Stack<T>[sizeTable])
        , _size(sizeTable)
    {}

    ~HashTable() { delete[] table; }

    int size() const { return _size; }

    void insert(int key, T value) { table[hashFunction(key)].push(key, value); }

    T find(int key)
    {
        Stack<T> stack = table[hashFunction(key)];

        int tempKey = 0;
        T tempValue;

        while (!stack.empty()) {
            tempKey = stack.Top()->key;
            tempValue = stack.Top()->value;
            stack.pop();
            if (tempKey == key) {
                return tempValue;
            }
        }

        return NULL;
    }
};

#endif // HASHTABLE_H
