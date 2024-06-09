#ifndef DEVIDEDQUEUE_H
#define DEVIDEDQUEUE_H

#include "Queue.h"


class DevidedQueue : public Queue<int> {
public:
    void devide(DevidedQueue& pos, DevidedQueue& neg) {
        pos.clear();
        neg.clear();
        while (_first != nullptr) {
            DevidedQueue& target = (_first->data > 0) ? pos : neg;
            if (target.empty()) {
                target._last = target._first = _first;
                _first->next = nullptr;
                _first = _first->prev;
                target._last->prev = nullptr;
            } else {
                target._last->prev = _first;
                _first->next = target._last;
                target._last = _first;
                _first = _first->prev;
                target._last->prev = nullptr;
            }
            ++target._size;
        }
        _size = 0;
        _first = _last = nullptr;
    }
};


#endif // DEVIDEDQUEUE_H
