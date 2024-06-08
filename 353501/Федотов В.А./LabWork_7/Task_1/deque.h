#include <iostream>

template<typename T>
class TraversableDeque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* current;
    int size;
    bool isRing;
    
public:
    class Iterator {
    private:
        Node* node;

    public:
        Iterator(Node* n) : node(n) {}

        T& operator*() {
            return node->data;
        }

        Iterator& operator++() {
            node = node->next;
            return *this;
        }

        Iterator& operator--() {
            node = node->prev;
            return *this;
        }

        Iterator operator+(int offset) {
            Iterator result = *this;
            for (int i = 0; i < offset; ++i) {
                ++result;
            }
            return result;
        }

        Iterator operator-(int offset) {
            Iterator result = *this;
            for (int i = 0; i < offset; ++i) {
                --result;
            }
            return result;
        }

        bool operator==(const Iterator& other) {
            return node == other.node;
        }

        bool operator!=(const Iterator& other) {
            return !(*this == other);
        }
    };

    TraversableDeque() : head(nullptr), tail(nullptr), current(nullptr), size(0), isRing(false) {}

    ~TraversableDeque() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
            if (temp == head) break;
        }
    }

    void pushBack(const T& value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pushFront(const T& value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        
        size++;
    }

    void popBack() {
        if (tail == nullptr) return;

        Node *toBeDeleted = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete toBeDeleted;
        size--;
    }

    void popFront() {
        if (head == nullptr) return;

        Node *toBeDeleted = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete toBeDeleted;
        size--;
    }

    void convertToRing() {
        if (head == nullptr || head->next == nullptr) return;
        
        tail->next = head;
        head->prev = tail;
        
        current = head;
        isRing = true;
    }

    void moveForward() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
    }

    void moveBackward() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
        }
    }

    T getCurrent() {
        if (current != nullptr) {
            return  current->data;
        } else {
            std::cout << "No data";
            return T();
        }
    }

    int getCurrentIndex() {
        if (current != nullptr) {
            Node* temp = head;
            int index = 0;
            while (temp != current) {
                temp = temp->next;
                index++;
            }
            return index;
        } else {
            return -1; 
        }
    }

    int getSize() { return size; }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

};