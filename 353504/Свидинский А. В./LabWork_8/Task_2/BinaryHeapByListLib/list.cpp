#include "list.h"
#include <iostream>

template<typename T>
void List<T>::append(T value)
{
    std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    size++;
}

template<typename T>
void List<T>::printList() const
{
    std::shared_ptr<Node<T>> current = head;
    while (current)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

template<typename T>
T& List<T>::operator[](int i)
{
    if(i < size)
    {
        int index = 0;
        std::shared_ptr<Node<T>> current = head;

        while(index != i && current && current->next)
        {
            current = current->next;
            index++;
        }

        return current->data;
    }

    throw std::out_of_range("Out of range");
}

