#ifndef ITERATORDEQUE_H
#define ITERATORDEQUE_H
#include <cstddef>
#include "nodedeque.h"

template<class T>
class IteratorDeque {
public:
    IteratorDeque(NodeDeque<T> *node, size_t index) : current(node), index(index) {}

    IteratorDeque operator++(int) {
        IteratorDeque tmp = *this;
        ++(*this);
        return tmp;
    }

    IteratorDeque &operator--() {
        if (current != nullptr && index == 0) {
            current = current->prev;
            index = current != nullptr ? current->count - 1 : 0;
        } else if (current != nullptr) {
            --index;
        }
        return *this;
    }

    IteratorDeque operator--(int) {
        IteratorDeque tmp = *this;
        --(*this);
        return tmp;
    }

    T &operator*() const {
        return current->data[index];
    }

    IteratorDeque &operator++() {
        if (current != nullptr && index == current->count - 1) {
            current = current->next;
            index = 0;
        } else if (current != nullptr) {
            ++index;
        }
        return *this;
    }

    bool operator==(const IteratorDeque &other) const {
        return current == other.current && index == other.index;
    }

    bool operator!=(const IteratorDeque &other) const {
        return !(*this == other);
    }
private:
    NodeDeque<T> *current;
    size_t index;
};

#endif // ITERATORDEQUE_H
