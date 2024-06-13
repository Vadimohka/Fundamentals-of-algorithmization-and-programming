#ifndef ITERATOR_H
#define ITERATOR_H
#include "block.h"
#include <cstddef>

template<typename T>
class iterator
{
    block<T>*current;
    size_t ind;
public:
    iterator(block<T>*cur,size_t i)
    {
        current=cur;
        ind=i;
    }

    T& operator*() const
    {
        return current->data[ind];
    }

    bool operator==(const iterator &other) const
    {
        return current==other.current&&ind==other.ind;
    }

    bool operator!=(const iterator &other) const
    {
        return !(operator==(other));
    }

    iterator &operator++() {
        if (current != nullptr && ind == current->right)//next block
        {
            current = current->next;
            ind = current->left;
        }
        else if (current != nullptr)//next index
        {
            ind++;
        }
        return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
        if (current != nullptr && ind == current->right)//next block
        {
            current = current->next;
            ind = current->left;
        }
        else if (current != nullptr)//next index
        {
            ind++;
        }
        return tmp;
    }

};

#endif // ITERATOR_H
