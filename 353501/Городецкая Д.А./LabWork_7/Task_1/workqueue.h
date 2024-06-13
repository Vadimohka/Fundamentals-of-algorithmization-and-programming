#ifndef WORKQUEUE_H
#define WORKQUEUE_H

template<typename T>
class queue {
    struct Node {
        T value;
        Node *next = nullptr;

        Node(const T& val = T()) : value(val) {}
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    long long size_ = 0;

public:
    queue() = default;
    ~queue() { clear(); }

    void clear() {
        while (!empty())
            pop();
    }

    void push(const T& value) {
        Node *el = new Node(value);
        size_++;
        if (!head) {
            head = tail = el;
        } else {
            tail->next = el;
            tail = el;
        }
    }

    void pop() {
        if (!head) {
            throw "No elements in queue";
        }

        Node *el = head;
        head = head->next;
        delete el;
        size_--;
    }

    T &front() { return head->value; }

    T &back() { return tail->value; }

    long long size() const { return size_; }

    bool empty() const { return size_ == 0; }
};

#endif // WORKQUEUE_H
