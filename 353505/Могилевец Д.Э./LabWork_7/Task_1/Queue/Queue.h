#ifndef QUEUE_H
#define QUEUE_H

#include <QVector>

template<typename T>
class Queue {
    struct Data {
        T inf;
        Data *next = nullptr;

        Data(const T &inf = T(), Data *next = nullptr) : inf(inf), next(next) {}
    };

    Data *head = nullptr;
    Data *tail = nullptr;

public:
    Queue() {};

    void push(const T &val) {
        Data *elem = new Data();
        elem->inf = val;

        if (head == nullptr) {
            head = elem;
            tail = elem;
        } else {
            tail->next = elem;
            tail = elem;
        }
    }

    T pop() {
        if (!head) throw "Queue is empty";
        Data *elem = head;
        head = head->next;
        return elem->inf;
        delete elem;

    }

    void insertAtPosition(const T &val, int pos) {
        if (pos < 0 || pos > size()) {
            throw "Invalid position";
            return;
        } else if (pos == size()) {
            push(val);
            return;
        }

        Data *elem = new Data(val);
        if (pos == 0) {
            elem->next = head;
            head = elem;
            return;
        }

        Data* prev = nullptr;
        Data* curr = head;

        while (pos) {
            prev = curr;
            curr = curr->next;
            pos--;
        }

        elem->next = curr;
        prev->next = elem;

        if (pos == size()) {
            tail = elem;
        }
    }


    QVector<T> toVector(){
        QVector<T> result;
        Data *cur = head;
        while (cur) {
            result.push_back(cur->inf);
            cur = cur->next;
        }
        return result;
    }

    virtual ~Queue() {
        while (!empty()) pop();
    }

    bool empty() const { return !head; }

    int size() const {
        int count = 0;
        Data *cur = head;
        while (cur) {
            ++count;
            cur = cur->next;
        }
        return count;
    }

    T &front() const {
        if (!head) {
            throw "Queue is empty";
        }
        return head->inf;
    }

    T &back() const {
        if (!tail) {
            throw "Queue is empty";
        }
        return tail->inf;
    }

    void clear() {
        while (!empty()) pop();
    }
};
#endif // QUEUE_H
