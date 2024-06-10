#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>

template<typename T>
class Deque
{
private:
    struct Node
    {
        T data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    Deque() = default;

    T &at(size_t pos)
    {
        size_t sz = size();
        if (pos >= sz) {
            throw "Неверный индекс";
        } else {
            Node *cur = head;
            for (size_t i = 0; i < pos; i++) {
                cur = cur->next;
            }
            return cur->data;
        }
    }

    void pushBack(T value)
    {
        Node *temp = new Node;
        temp->data = value;
        if (isEmpty()) {
            tail = temp;
            head = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void pushFront(T value)
    {
        Node *temp = new Node;
        temp->data = value;
        if (isEmpty()) {
            tail = temp;
            head = temp;
        } else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            if (tail != head) {
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            } else {
                delete tail;
                tail = nullptr;
                head = nullptr;
            }
        }
    }

    void popFront()
    {
        if (!isEmpty()) {
            if (tail != head) {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
            } else {
                delete head;
                tail = nullptr;
                head = nullptr;
            }
        }
    }

    bool isEmpty() { return head == nullptr && tail == nullptr; }

    void clear()
    {
        while (!isEmpty()) {
            popFront();
        }
    }

    size_t size()
    {
        size_t count = 0;
        Node *cur = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void swapMinMax()
    {
        if (!head || head == tail) {
            return;
        }

        Node *minNode = head;
        Node *maxNode = head;
        Node *curr = head->next;

        while (curr != nullptr) {
            if (curr->data < minNode->data) {
                minNode = curr;
            }
            if (curr->data > maxNode->data) {
                maxNode = curr;
            }
            curr = curr->next;
        }

        if (minNode != maxNode) {
            if (minNode->next == maxNode) {
                minNode->next = maxNode->next;
                maxNode->prev = minNode->prev;
                minNode->prev = maxNode;
                maxNode->next = minNode;
            } else if (maxNode->next == minNode) {
                maxNode->next = minNode->next;
                minNode->prev = maxNode->prev;
                maxNode->prev = minNode;
                minNode->next = maxNode;
            } else {
                Node *tempNext = minNode->next;
                Node *tempPrev = minNode->prev;

                minNode->next = maxNode->next;
                minNode->prev = maxNode->prev;
                maxNode->next = tempNext;
                maxNode->prev = tempPrev;

                if (minNode->next) {
                    minNode->next->prev = minNode;
                }
                if (minNode->prev) {
                    minNode->prev->next = minNode;
                }
                if (maxNode->next) {
                    maxNode->next->prev = maxNode;
                }
                if (maxNode->prev) {
                    maxNode->prev->next = maxNode;
                }
            }

            if (head == minNode) {
                head = maxNode;
            } else if (head == maxNode) {
                head = minNode;
            }
            if (tail == minNode) {
                tail = maxNode;
            } else if (tail == maxNode) {
                tail = minNode;
            }
        }
    }
};

#endif // DEQUE_H
