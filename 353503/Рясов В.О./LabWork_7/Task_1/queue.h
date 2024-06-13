#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <cstdint>
#include <iterator>

class Queue
{
private:
    struct Node{
        Node *prev;
        Node *next;
        int data;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node *_head;
    Node *_tail;
    Node *_dummy;
    size_t _sz;
public:
    Queue();
    ~Queue();
    void pushback(int val);
    void popback();
    void clear();
    bool empty();
    size_t size();
    Node *getHead();
    Node *getTail();

    class QueueIterator
    {
    private:
        Node* node;
        /*Node* head;
        bool at_end;*/
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using pointer = int*;
        using reference = int&;
        using iterator_category = std::bidirectional_iterator_tag;

        QueueIterator(Node* node)//, Node* head, bool at_end = false)
            : node(node)// head(head), at_end(at_end) {}
        {}
        reference operator*() const { return node->data; }
        pointer operator->() const { return &(node->data); }

        QueueIterator& operator++(){
                node = node->next;
                //if (node == head) at_end = true;
            return *this;
        }

        QueueIterator operator++(int) {
            QueueIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        QueueIterator& operator--(){
                node = node->prev;

            return *this;
        }

        QueueIterator operator--(int) {
            QueueIterator tmp = *this;
            --(*this);
            return tmp;
        }

        bool operator==(const QueueIterator& other) const {
            return node == other.node;
        }

        bool operator!=(const QueueIterator& other) const {
            return !(*this == other);
        }

    };

    QueueIterator begin() {
        return QueueIterator(_head);
    }

    QueueIterator end() {
        return QueueIterator(_tail);
    }

    friend class QueueIterator;
};

#endif // QUEUE_H
