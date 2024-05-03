#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include <QTextStream>

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

    void push(const T &);

    void pop();

    void insertAtPosition(const T &, int);

    void moveElements(int, int, int);

    QVector<T> toVector();

    virtual ~Queue();

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
};

template<typename T>
void Queue<T>::push(const T &val) {
    Data *elem = new Data();
    elem->inf = val;

    if (head == nullptr) {
        head = tail = elem;
    } else tail = tail->next = elem;
}

template<typename T>
void Queue<T>::pop() {
    if (!head) throw "Queue is empty";
    Data *elem = head;
    head = head->next;
    delete elem;
}

template<typename T>
void Queue<T>::insertAtPosition(const T &val, int pos) {
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
        if (!tail) {
            tail = elem;
        }
    } else {
        Data *prev = nullptr;
        Data *cur = head;
        for (int i = 0; i < pos; ++i) {
            prev = cur;
            cur = cur->next;
        }
        elem->next = cur;
        prev->next = elem;
        if (pos == size()) {
            tail = elem;
        }
    }
}

template<typename T>
Queue<T>::~Queue() {
    while (head) {
        Data *elem = head;
        head = head->next;
        delete elem;
    }
}

template<typename T>
void Queue<T>::moveElements(int n, int m, int k) {
    bool rev = false;
    if (k < 0) {
        k = -k;
        rev = true;
    }
    if (n < 0 || m >= size() || n > m || k > size()) {
        throw "Invalid positions";
        return;
    }

    Queue<T> removedElements;
    Queue<T> removedElements1;
    for (int i = 0; i < n; ++i) {
        removedElements.push(front());
        pop();
    }
    for (int i = 0; i < m - n; ++i) {
        removedElements1.push(front());
        pop();
    }

    if (!rev){
        for (int i = 0; i < n; ++i) {
            insertAtPosition(removedElements.front(), i);
            removedElements.pop();
        }

        for (int i = 0; i < m - n; ++i) {
            insertAtPosition(removedElements1.front(), k + i + n);
            removedElements1.pop();
        }
    } else {
        for (int i = 0; i < n; ++i) {
            insertAtPosition(removedElements.front(), i);
            removedElements.pop();
        }
        for (int i = 0; i < m - n; ++i) {
            insertAtPosition(removedElements1.front(), n + i - k);
            removedElements1.pop();
        }
    }
}

template<typename T>
QVector<T> Queue<T>::toVector() {
    QVector<T> result;
    Data *cur = head;
    while (cur) {
        result.push_back(cur->inf);
        cur = cur->next;
    }
    return result;
}
#endif // QUEUE_H
