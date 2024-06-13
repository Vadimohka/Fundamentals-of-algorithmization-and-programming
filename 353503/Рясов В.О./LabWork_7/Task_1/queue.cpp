#include "queue.h"

Queue::Queue() : _tail(nullptr), _head(nullptr), _sz(0)
{
    _dummy = new Node(0);
    _dummy->next = _dummy; // Устанавливаем next фиктивного узла на самого себя
    _dummy->prev = _dummy; // Устанавливаем prev фиктивного узла на самого себя
}

void Queue::pushback(int val)
{
    Node* newNode = new Node(val);
    if(_sz == 0){
        _head = _tail = newNode;
        _head->next = _head;
        _head->prev = _head;
    }
    else {
        _tail->next = newNode;
        newNode->prev = _tail;
        newNode->next = _head;
        _head->prev = newNode;
        _tail = newNode;
    }
    ++_sz;
}

void Queue::popback()
{
    if (_sz == 0) return;

    if(_sz == 1){
        clear();
    }

    else{
        Node *tmp = _tail;
        _tail = _tail->prev;
        _tail->next = _head;
        _head->prev = _tail;
        delete tmp;
    }
    --_sz;
}

void Queue::clear()
{
    if (_sz == 0) return;
    Node* current = _head;
    do {
        Node* next = current->next;
        delete current;
        current = next;
    } while (current != _head);
    _head = _tail = nullptr;
    _sz = 0;
}

bool Queue::empty()
{
    if(_sz == 0){
        return true;
    }

    return false;
}

size_t Queue::size()
{
    return _sz;
}

Queue::Node *Queue::getHead()
{
    return _head;
}

Queue::Node *Queue::getTail()
{
    return _tail;
}

Queue::~Queue(){
    clear();
    delete _dummy;
}
