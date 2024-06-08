

#ifndef TASK3_STACK_H
#define TASK3_STACK_H


#include <vector>
#include <string>

template<typename T>
class Stack {

public:
    Stack() {};

    ~Stack() {
        while (_size != 0) {
            pop();
        }
    }

    struct Node {
        T data;
        Node* prev;
        Node(const T &data = T()) : data(data), prev(nullptr) {}
    };

    void clear() {
        while(_size != 0)
        {
            pop();
        }
    }

    void push(const T &data)
    {
        Node* _newNode = new Node(data);
        if(_size == 0 || _tail == nullptr)
        {
            _tail = _newNode;
        }
        else
        {
            _newNode->prev = _tail;
            _tail = _newNode;
        }
        _size ++;
    }

    T pop()
    {
        if(_size == 0)
        {
            throw "Empty queue";
        }
        T ret = _tail->data;
        Node* _temp = _tail->prev;
        delete _tail;
        _size --;
        _tail = _temp;
        return ret;
    }

    bool empty() const {
        return _size == 0;
    }

    int size() const {
        return _size;
    }

    T &top() const {
        if (_tail == nullptr) {
            throw "stack is empty";
        }
        return _tail->data;
    }

    std::string GetString()
    {
        std::string ret;
        auto _cur = _tail;
        while(_cur != nullptr)
        {
            int v = _cur->data;
            ret += std::to_string(v);
            ret += " ";
            _cur = _cur->prev;
        }
        return ret;
    }


private:
    Node* _tail = nullptr;
    int _size = 0;
};


#endif //TASK3_STACK_H
