#ifndef LIST_H
#define LIST_H

#include <memory>
template<typename T>
struct Node {
    T data;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;

    Node(T value) : data(value), next(nullptr), prev(std::weak_ptr<Node<T>>()) {}
};


template<typename T>
class List
{
public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void append(T value);
    void printList() const;
    T &operator [](int i);
    int size;

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;


};

#endif // LIST_H
