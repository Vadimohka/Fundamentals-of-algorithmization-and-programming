//
// Created by acryoz on 26.05.24.
//
#include <charconv>
#include <cstddef>
#include <iostream>

template <typename T>
class Queue {
    struct BaseNode {
        BaseNode* next;
        BaseNode* prev;
    };

    struct Node : BaseNode {
        T value;
    };

    BaseNode fake_head;
    size_t sz = 0;

   public:
    Queue() {
        this->fake_head.next = &this->fake_head;
        this->fake_head.prev = &this->fake_head;
        this->sz = 0;
    }

    Queue(const Queue& other) {
        this->sz = other.sz;
        this->fake_head.next = &this->fake_head;
        this->fake_head.prev = &this->fake_head;
        Node* other_cur_node = static_cast<Node*>(other.fake_head.next);
        while (other_cur_node != &other.fake_head) {
            this->push(other_cur_node->value);
            other_cur_node = static_cast<Node*>(other_cur_node->next);
        }
    }

    Queue& operator=(const Queue& other) {
        if (this == &other) {
            return *this;
        }
        BaseNode* current_node = this->fake_head.next;
        BaseNode* next_node;
        while (current_node != *this->fake_head) {
            next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
        this->sz = other.sz;
        this->fake_head.next = &this->fake_head;
        this->fake_head.prev = &this->fake_head;
        if (other.sz != 0) {
            Node* other_cur_node = static_cast<Node*>(other.fake_head.next);
            Node* cur_node = new Node;
            cur_node->value = other_cur_node->value;
            this->fake_head.next = cur_node;
            cur_node->prev = &this->fake_head;
            Node* new_node;
            while (other_cur_node != &other.fake_head) {
                new_node = new Node;
                new_node->value = other_cur_node->value;
                new_node->prev = cur_node;
                new_node->prev->next = new_node;
                cur_node = new_node;
                other_cur_node = static_cast<Node*>(other_cur_node->next);
            }
            cur_node->next = &this->fake_head;
            this->fake_head.prev = cur_node;
        }
        return *this;
    }

    T& front() { return static_cast<Node*>(this->fake_head.next)->value; }

    const T& front() const {
        return static_cast<Node*>(this->fake_head.next)->value;
    }

    T& back() { return static_cast<Node*>(this->fake_head.prev)->value; }

    const T& back() const {
        return static_cast<Node*>(this->fake_head.prev)->value;
    }

    size_t size() { return this->sz; }

    bool empty() { return this->sz == 0; }

    void push(const T& val) {
        Node* new_node = new Node;
        new_node->value = T(val);
        new_node->next = &this->fake_head;
        new_node->prev = this->fake_head.prev;
        this->fake_head.prev->next = new_node;
        this->fake_head.prev = new_node;
        this->sz += 1;
    }

    void pop() {
        Node* tmp = static_cast<Node*>(this->fake_head.next);
        this->fake_head.next = this->fake_head.next->next;
        delete tmp;
        this->fake_head.next->prev = &this->fake_head;
        this->sz -= 1;
    }

    void cycle_pop() {
        this->push(this->front());
        this->pop();
    }

    void print() {
        Node* cur_node = static_cast<Node*>(this->fake_head.next);
        while (cur_node != &this->fake_head) {
            std::cout << cur_node->value << ' ';
            cur_node = static_cast<Node*>(cur_node->next);
        }
        std::cout << '\n';
    }

    ~Queue() {}
};
