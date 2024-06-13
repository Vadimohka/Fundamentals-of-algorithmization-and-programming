#ifndef DEQUE_H
#define DEQUE_H

#include "iterator.h"
#include "node.h"
#include <cstddef>


template<typename T>
class Deque
{
private:
    Node<T> *head;
    Node<T> *tail;
    size_t sz;

public:
    Deque() : head(nullptr), tail(nullptr), sz(0) {}

    ~Deque()
    {
        clear();
    }

    void push_back(const T& value) // добавление элемента в конец
    {
        if (tail == nullptr || tail->tail == 3)
        {
            Node<T> *newNode = new Node<T>();
            if (empty())
            {
                newNode->next = newNode;
                newNode->prev = newNode;
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail = newNode;
            } 
        }
        else
        {
            ++tail->tail;
        }

        tail->value[tail->tail] = value;
        sz++;
    }


    void push_front(const T &value) // добавление элемента в начало
    {
        if (head == nullptr || head->head == 0)
        {
            Node<T> *newNode = new Node<T>();
            if (empty())
            {
                newNode->value[0] = value;
                newNode->next = newNode;
                newNode->prev = newNode;
                head = tail = newNode;
            }
            else
            {
                newNode->value[3] = value;
                newNode->head = 3;
                newNode->tail = 3;
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail->next = newNode;
                head = newNode;
            }

            ++sz;
        }
        else
        {
            --(head->head);
            head->value[head->head] = value;
            sz++;
        }
    }


    void pop_back() // удаление элемента из конца
    {
        if (!empty())
        {
            --sz;

            if (tail != nullptr)
            {
                --tail->tail;
            }

            if (tail != nullptr && tail->tail == -1)
            {
                Node<T> *temp = tail;
                if (tail == head)
                {
                    head = tail = nullptr;
                }
                else
                {
                    tail = tail->prev;
                    if (tail != nullptr)
                    {
                        tail->next = head;
                    }

                    head->prev = tail;
                }

                delete temp;
            }
        }
    }


    void pop_front() // удаление элемента из начала
    {
        if (!empty())
        {
            --sz;

            if (head != nullptr) ++head->head;
            if (head != nullptr && head->head == 4)
            {
                Node<T> *temp = head;
                if (head == tail)
                {
                    head = tail = nullptr;
                }
                else
                {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = tail;
                    tail->next = head;
                }

                delete temp;
            }
        }
    }


    bool empty() const
    {
        return sz == 0;
    }


    size_t size() const
    {
        return sz;
    }


    void clear() // почистить весь deque
    {
        while (!empty())
        {
            pop_back();
        }
    }


    Iterator<T> begin()
    {
        return Iterator(head != nullptr ? head : nullptr, head != nullptr ? head->head : 0);
    }


    Iterator<T> end()
    {
        if (tail != nullptr)
        {
            return ++Iterator<T>(tail, tail->tail);
        }
        else
        {
            return Iterator<T>(nullptr, 0);
        }
    }
};


#endif // DEQUE_H
