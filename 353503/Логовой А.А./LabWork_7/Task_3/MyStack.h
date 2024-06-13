#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>
#include <QString>
template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* _top;
    size_t _size{};

public:
    Stack() : _top(nullptr) {}

    ~Stack() {
        while (_top != nullptr) {
            Node* temp = _top;
            _top = _top->next;
            delete temp;
        }
    }

    Stack(Stack<T> &other) : _top(nullptr) ,_size(0){
        Node* temp = other._top;
        while (temp != nullptr)
        {
            push(temp->data);
            temp = temp->next;
        }
    }
    bool isEmpty() {
        return _size == 0;
    }

    void push(T element) {
        Node* temp = new Node();
        temp->data = element;
        temp->next = _top;
        _top = temp;
        _size++;
    }

    void pop() {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        Node* temp = _top;
        _top = _top->next;
        delete temp;
        _size--;
    }

    const T& peek() {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return _top->data;
    }

    const T& top() {
        if (_size == 0) {
            throw std::out_of_range("Stack is empty");
        }
        return _top->data;
    }

    size_t size() const {
        return _size;
    }

    QString toString(){
        QString res = "";
        Node* temp = _top;
        while(temp != nullptr){
            res += std::to_string(temp->data) + " ";
            temp = temp->next;
        }
        return res;
    }
};

#endif // MYSTACK_H
