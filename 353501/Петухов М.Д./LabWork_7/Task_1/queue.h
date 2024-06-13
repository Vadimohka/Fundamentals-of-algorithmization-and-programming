#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QTextStream>

template<typename T>
class Queue {
    struct Data {
        T data;
        Data *next = nullptr;
        Data *prev = nullptr;

        Data(const T &data = T(), Data *next = nullptr, Data *prev = nullptr) : data(data), next(next), prev(prev) {}
    };

    Data *head = nullptr;
    Data *tail = nullptr;

public:
    Queue() {};

    bool isEmpty() const;

    void insertBack(const T &);
    void insertFront(const T &);

    void deleteFront();
    void deleteBack();    


    virtual ~Queue();


    int size() const {
        int count = 0;
        Data *cur = head;
        while (cur) {
            ++count;
            cur = cur->next;
        }
        return count;
    }

    T &front() const {
        if (isEmpty()) {
            throw "Queue is empty";
        }
        return head->data;
    }

    T &back() const {
        if (!tail) {
            throw "Queue is empty";
        }
        return tail->data;
    }
};

template<typename T>
bool Queue<T>::isEmpty() const {
    return (head == nullptr && tail == nullptr);
}

template<typename T>
void Queue<T>::insertBack(const T &val) {
    Data *elemPtr = new Data();
    elemPtr->data = val;
    elemPtr->next = nullptr;
    elemPtr->prev = nullptr;

    if (head == nullptr) {
        head = elemPtr;
        tail = elemPtr;
    } 
    else{
        elemPtr->prev = tail;
        tail->next = elemPtr;
        //на этом моменте tail указывает на предпоследний 
        //элемент(не на только что созданный)
        tail = elemPtr;
        //теперь сам tail указывает на последний
    } 
}

template<typename T>
void Queue<T>::insertFront(const T &val) {
    Data *elemPtr = new Data();
    elemPtr->data = val;
    elemPtr->next = nullptr;    
    elemPtr->prev = nullptr;

    if (head == nullptr) {
        head = elemPtr;
        tail = elemPtr;
    }
    else{
        elemPtr->next = head;
        head->prev = elemPtr;
        head = elemPtr;
    } 
}

template<typename T>
void Queue<T>::deleteFront() {
    if (isEmpty()) {
        throw "Queue is empty";
    }

    /*if(front == tail){
        delete front;
        front = tail = nullptr;
    }
    else{
        Data* ptr = front;
        front = front->next;
        front->prev = nullptr;
        delete ptr;
    }*/

    Data* temp = head;
    head = head->next;


    if(head == nullptr){
        tail = nullptr;
    }
    else{
        head->prev = nullptr;
    }
    delete temp;
}

template<typename T>
void Queue<T>::deleteBack() {
    if (isEmpty()) {
        throw "Queue is empty";
    }

    Data* temp = tail;
    tail = tail->prev;
    if(tail == nullptr){
        head = nullptr;
    }
    else{
        tail->next = nullptr;
    }
    delete temp;
}

template<typename T>
Queue<T>::~Queue() {
    while (head) {
        Data *elem = head;
        head = head->next;
        delete elem;
    }
}
#endif // QUEUE_H