#ifndef CIRCULAR_DEQUE_H
#define CIRCULAR_DEQUE_H

#include <QVector>

template<typename T>
class CircularDeque {
    struct Node {
        T inf;
        Node *next = nullptr;
        Node *prev = nullptr;

        Node(const T &inf = T(), Node *next = nullptr, Node *prev = nullptr)
            : inf(inf), next(next), prev(prev) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    Node *current = nullptr;
    int currentIndexVal = 0;

public:
    CircularDeque() {}

    void push(const T &val) {
        Node *elem = new Node(val);
        if (!head) {
            head = tail = current = elem;
            elem->next = elem->prev = elem;
        } else {
            elem->prev = tail;
            elem->next = head;
            tail->next = elem;
            head->prev = elem;
            tail = elem;
        }
    }

    T pop() {
        if (!head) throw "Queue is empty";
        Node *elem = head;
        if (head == tail) {
            head = tail = current = nullptr;
        } else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            if (current == elem) current = head;
        }
        T val = elem->inf;
        delete elem;
        return val;
    }

    void clear() {
        while (head != tail) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        head = tail = current = nullptr;
    }

    QVector<T> toVector() const {
        QVector<T> result;
        if (!head) return result;
        Node *cur = head;
        do {
            result.push_back(cur->inf);
            cur = cur->next;
        } while (cur != head);
        return result;
    }

    int size() const {
        int count = 0;
        if (!head) return count;
        Node *cur = head;
        do {
            ++count;
            cur = cur->next;
        } while (cur != head);
        return count;
    }

    T &currentValue() const {
        if (!current) throw "Queue is empty";
        return current->inf;
    }

    int currentIndex() const {
        return currentIndexVal;
    }

    void moveNext() {
        if (!current) return;
        current = current->next;
        currentIndexVal = (currentIndexVal + 1) % size();
    }

    void movePrev() {
        if (!current) return;
        current = current->prev;
        currentIndexVal = (currentIndexVal - 1 + size()) % size();
    }
};

#endif // CIRCULAR_DEQUE_H
