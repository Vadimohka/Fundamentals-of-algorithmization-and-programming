#ifndef STACK_H
#define STACK_H

#include <QVector>
class Stack {

public:
    struct Item {
        int key;
        int value;
        Item()
            : key(0)
            , value(0)
        {}
        Item(int key, int value)
            : key(key)
            , value(value)
        {}
    };

    Stack();
    bool isEmpty();
    bool isFull();
    void push(int key, int value);

    QVector<int> toQVectorValue();
    QVector<int> toQVectorKey();

    void clear();
    Item pop();
    Item peek();

private:
    static const int MAX_SIZE = 1000;
    Item items[MAX_SIZE];
    int top;

};

#endif // STACK_H
