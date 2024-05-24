#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QListWidget>
#include <cstddef>
#include <cstdint>

template<typename T>
class Stack
{
private:
    struct Node
    {
        Node *next;
        int64_t key;
        T value;
        Node(int64_t key, T value)
            : key(key)
            , value(value)
            , next(nullptr)
        {}
    };

    Node *top;

public:
    Stack();
    Stack(const Stack<T> &other);
    ~Stack();

    void push(int64_t key, T value);
    void pop(int64_t &key, T &value);
    void pop();
    void clear();
    bool empty();
};

template<typename T>
class HashTable
{
protected:
    Stack<T> *table;

private:
    size_t _size;

    int64_t hashFunction(int64_t key);

public:
    explicit HashTable(size_t sizeTable);
    virtual ~HashTable();

    size_t size() const;
    virtual void insert(int64_t key, T value);
    T find(int64_t key);
};

template<typename T>
class HashTableMax : public HashTable<T>
{
private:
    int64_t _maxKey;

public:
    explicit HashTableMax(size_t sizeTable);
    ~HashTableMax() override;

    void insert(int64_t key, T value) override;
    int64_t getMaxKey();
    T findMax();
    void inputToTableWidget(QListWidget &widget);
};

#endif // HASHTABLE_H
