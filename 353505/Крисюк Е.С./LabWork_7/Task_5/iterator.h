#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template<typename t>

class
    Iterator
{

private:
    Node<t>* current_node;
    int current_index;

public:


    Iterator(Node<t>* node, int index) {

        current_node = node;
        current_index = index;
    }

    Iterator &operator++(int) {
        Iterator tmp = *this;

        ++(*this);
        return tmp;
    }

    Iterator &operator--() {

        if (current_node != nullptr && current_index == 0) {

            current_node = current_node -> prev;
            current_index = 3;

        }
        else if (current_node!= nullptr) {
            --current_index;
        }

        return *this;
    }

    Iterator operator--(int) {
        Iterator tmp = *this;
        --(*this);
        return tmp;
    }

    t &operator*() {
        return current_node -> data[current_index];
    }

    Iterator &operator++() {
        if (current_node != nullptr && current_index == current_node -> count - 1) {
            current_node= current_node -> next;
            current_index = 0;
        }
        else if (current_node!= nullptr) {
            ++current_index;
        }
        return *this;
    }

    bool operator == (const Iterator& other) const {
        return current_node == other.current_node && current_index == other.current_index;
    }

    bool operator != (const Iterator& other) const {
        return !(*this == other);
    }

};

#endif // ITERATOR_H
