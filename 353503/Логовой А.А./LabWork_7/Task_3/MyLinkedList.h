#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <stdexcept>
#include <QString>
#include<QDebug>
template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        int key;
        Node* next;
    };
    size_t _size;
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void push(T element) {
        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = head;
        head = newNode;
        _size++;
    }

    QString toString() {
        QString res = "";
        Node* current = head;
        while (current != nullptr) {
            res += std::to_string(current->data) + " ";
            current = current->next;
        }
        return res;
    }

    bool contains(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insert(T element, size_t position) {
        if(position == _size)
        {
            push(element);
            return;
        }

        else if (position > _size) { throw std::out_of_range ("You are out of range");}

        Node* newNode = new Node();
        newNode->data = element;

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* current = head;
            for (size_t i = 1; i < position; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        _size++;
    }


    void remove(T value) {

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                _size--;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    void removeAt(size_t position) {
        if (_size == 0) { throw std::out_of_range("List is empty"); }
        else if (position >= _size) { throw std::out_of_range("Index out of range"); }

        Node* current = head;
        Node* prev = nullptr;

        if (position == 0) {
            head = current->next;
            delete current;
            _size--;
            return;
        }

        for (size_t i = 0; i < position; ++i) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;
        _size--;
    }

    bool isEmpty() const{
        return _size == 0;
    }

    int getKey(Node* node){
        node->key;
    }

    void clear() {
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
            }

        head = nullptr;
        _size = 0;
    }

};

#endif // MYLINKEDLIST_H

