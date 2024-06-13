#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Deque {
public:

    Node* front;
    Node* back;
    int size;


    Deque()
    {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    void pushFront(int data) {
        Node* node = new Node(data);
        if (isEmpty())
        {
            front = back = node;
            front->next = back;
            back->prev = front;
        }
        else {
            node->next = front;
            front->prev = node;
            front = node;
            node->prev = back;
            back->next = front;
        }
        size++;
    }

    void pushBack(int data) {
        Node* node = new Node(data);
        if (isEmpty()) {
            front = back = node;
            front->next = back;
            back->prev = front;
        }
        else {
            node->prev = back;
            back->next = node;
            back = node;
            node->next = front;
            front->prev = back;
        }
        size++;
    }

    void popFront() {
        if (isEmpty()) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = back;
            back->next = front;
        }
        else {
            back = nullptr;
        }
        delete temp;

        size--;
    }

    void popBack() {
        if (isEmpty()) {
            return;
        }
        Node* temp = back;
        back = back->prev;
        if (back != nullptr) {
            back->next = front;
            front->prev = back;
        }
        else {
            front = nullptr;
        }
        delete temp;
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void makeCircular() {
        front->prev = back;
        back->next = front;
    }
};

//int main() {
//    Deque dq;
//    Node* buf;
//    // Добавление элементов в начало и конец очереди
//    dq.pushBack(1);
//    dq.pushBack(2);
//    dq.pushBack(3);
//    dq.pushBack(4);

//    // Вывод размера очереди
//    std::cout << "Size of deque: " << dq.getSize() << std::endl;

//    buf = dq.front;
//    for (int i = 0; i < 20; i++)
//    {
//        std::cout << buf->data << " ";
//        buf = buf->next;
//    }

//    // Удаление элементов из начала и конца очереди
//    dq.popFront();
//    dq.popBack();

//    std::cout << "\n\n";

//    buf = dq.front;
//    for (int i = 0; i < 20; i++)
//    {
//        std::cout << buf->data << " ";
//        buf = buf->prev;
//    }

//    // Вывод размера очереди после удаления элементов
//    std::cout << "Size of deque after popping: " << dq.getSize() << std::endl;

//    return 0;
//}

#endif // MYQUEUE_H
