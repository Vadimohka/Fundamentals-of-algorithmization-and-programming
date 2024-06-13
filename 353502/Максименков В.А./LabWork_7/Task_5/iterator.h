#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"
#include <cstddef>

template<class T>
class Iterator {
public:
    Node<T> *current;
    size_t index;

public:
    Iterator(Node<T> *node, size_t index) : current(node), index(index) {}

    T &operator*() const {
        return current->value[index];
    }

    Iterator &operator++() {
        if (current != nullptr && index == current->tail) {
            current = current->next;
            index = current->head;
        } else if (current != nullptr) {
            ++index;
        }
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    Iterator &operator--() {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    Iterator operator--(int) {
        if (current != nullptr && index == current->head) {
            current = current->prev;
            index = current->tailz;
        } else if (current != nullptr) {
            index--;
        }
        return *this;
    }

    bool operator==(const Iterator &other) const {
        return current == other.current && index == other.index;
    }

    bool operator!=(const Iterator &other) const {
        return !(*this == other);
    }
};
#endif // ITERATOR_H
