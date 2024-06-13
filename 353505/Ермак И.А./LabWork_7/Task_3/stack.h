#ifndef STACK_H
#define STACK_H

#include <vector>
#include <utility>

struct KeyValuePair {
    int key;
    int value;
};

class Stack {
public:
    void push(const KeyValuePair &kv);
    void pop();
    KeyValuePair top() const;
    bool isEmpty() const;
    std::vector<KeyValuePair> getElements() const;

private:
    std::vector<KeyValuePair> elements;
};

#endif // STACK_H
