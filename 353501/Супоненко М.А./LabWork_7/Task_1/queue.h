#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(int val);
    int dequeue();
    bool isEmpty() const;
    void removeDuplicates();
    void display() const;
    Node* getHead() const;  // Добавленный метод

private:
    Node* head;
    Node* tail;
};

#endif // QUEUE_H
