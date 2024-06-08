#include <cstddef>
#include <stdexcept>

template<typename T>
class HashMap {
protected:
    struct Node {
        unsigned int key;
        Node* next;
        T value;

        Node(unsigned int key, Node* next, const T& value)
            : key(key), next(next), value(value) {}
    };

protected:
    Node** nodes;
    size_t size;

protected:
    unsigned int hash(unsigned int key) {
        return key % size;
    }

    void init() {
        nodes = new Node*[size];
        for (size_t i = 0; i < size; i++) {
            nodes[i] = nullptr;
        }
    }

public:

    HashMap(size_t size) : size(size) {
        init();
    }

    ~HashMap() {
        clear();
        delete[] nodes;
    }

    void clear() {
        for (size_t i = 0; i < size; i++) {
            Node* node = nodes[i];
            while (node != nullptr) {
                Node* next = node->next;
                delete node;
                node = next;
            }
        }
    }

    void remove(unsigned int key) {
        unsigned int index = hash(key);

        Node* current = nodes[index];
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    nodes[index] = current->next;
                } else {
                    previous->next = current->next;
                }

                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }

    void insert(unsigned int key, const T& value) {
        remove(key);

        unsigned int index = hash(key);
        Node* newNode = new Node(key, nodes[index], value);
        nodes[index] = newNode;
    }

    bool contains(unsigned int key) {
        unsigned int index = hash(key);

        Node* node = nodes[index];
        while (node != nullptr) {
            if (node->key == key) {
                return true;
            }

            node = node->next;
        }

        return false;
    }

    T& get(unsigned int key) {
        unsigned int index = hash(key);

        Node* node = nodes[index];
        while (node != nullptr) {
            if (node->key == key) {
                return node->value;
            }

            node = node->next;
        }

        throw std::invalid_argument("Key not found");
    }
};