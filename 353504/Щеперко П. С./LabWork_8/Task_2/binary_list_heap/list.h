#ifndef LIST_H
#define LIST_H

#include <memory>
#include <QException>
#include <QStringList>

class Node {
public :
    int data;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    Node(int value) : data(value), next(nullptr), prev(std::weak_ptr<Node>()) {}
};

class List
{
public:
    List() : size(0), head(nullptr), tail(nullptr) {}
    void append(int value);
    QStringList printList() const;
    int &operator [](int i);
    int size;

private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
};

#endif // LIST_H
