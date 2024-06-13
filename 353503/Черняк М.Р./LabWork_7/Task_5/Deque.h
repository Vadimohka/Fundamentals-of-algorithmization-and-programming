#include <stdexcept>

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t deque_size;

    void deleteNodes() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
        deque_size = 0;
    }

public:
    Deque() : head(nullptr), tail(nullptr), deque_size(0) {}

    ~Deque() {
        clear();
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++deque_size;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++deque_size;
    }

    void pop_back() {
        if (!tail) {
            throw std::out_of_range("Deque is empty");
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        --deque_size;
    }

    void pop_front() {
        if (!head) {
            throw std::out_of_range("Deque is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        --deque_size;
    }

    void clear() {
        deleteNodes();
    }

    size_t size() const {
        return deque_size;
    }

    bool empty() const {
        return deque_size == 0;
    }

    class iterator {
    private:
        Node* node;
    public:
        iterator(Node* node) : node(node) {}

        T& operator*() {
            return node->data;
        }

        iterator& operator++() {
            node = node->next;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            node = node->next;
            return tmp;
        }

        iterator& operator--() {
            node = node->prev;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            node = node->prev;
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return node == other.node;
        }

        bool operator!=(const iterator& other) const {
            return node != other.node;
        }
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    T& operator[](size_t index) {
        if (index >= deque_size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }
};
