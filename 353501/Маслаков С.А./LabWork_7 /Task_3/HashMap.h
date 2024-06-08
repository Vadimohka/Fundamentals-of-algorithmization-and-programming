
#ifndef LAB7_HASHMAP_H
#define LAB7_HASHMAP_H
#include <cstddef>
#include <stdexcept>
#include <QIntegerForSize>

template<typename T>
class HashMap {
protected:
    struct Node {
        uint key;
        Node *next;
        T value;

        Node(long key, Node *next, const T &value)
                : key(key), next(next), value(value) {}
    };

    Node **buckets;
    size_t size;

    uint hash (uint key) { return key % size;  }

public:
    HashMap() : size(10) {
        buckets = new Node *[size];
        for (int i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }
public:
    void removeAllEvenKeys(HashMap<int>& hashMap) {
        for (size_t i = 0; i < hashMap.size; i++) {
            HashMap<int>::Node* prevNode = nullptr;
            HashMap<int>::Node* currNode = hashMap.buckets[i];

            while (currNode != nullptr) {
                if (currNode->key % 2 == 0) { // If the key is even
                    if (prevNode == nullptr) { // If it's the first node in the bucket
                        hashMap.buckets[i] = currNode->next;
                    } else {
                        prevNode->next = currNode->next;
                    }

                    HashMap<int>::Node* temp = currNode;
                    currNode = currNode->next;
                    delete temp;
                } else {
                    prevNode = currNode;
                    currNode = currNode->next;
                }
            }
        }
    }

    HashMap(size_t size) : size(size) {
        buckets = new Node *[size];
        for (int i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }

    ~HashMap() {
        clear();
        delete [] buckets;
    }

    /*void clear() {
        for (int i = 0; i < size; i++) {
            Node *node = buckets[i];
            while (node != nullptr) {
                Node *next = node->next;
                delete node;
                node = next;
            }
        }
    }*/
    void clear() {
        for (int i = 0; i < size; i++) {
            Node* node = buckets[i];
            while (node != nullptr) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
            buckets[i] = nullptr;
        }
    }

    void remove(long key) {
        uint index = hash(key);

        Node *current = buckets[index];
        Node *previous = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (previous == nullptr) {
                    buckets[index] = current->next;
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

    void insert(uint key, const T& value) {
        remove(key);

        uint index = hash(key);
        Node *newNode = new Node(key, buckets[index], value);
        buckets[index] = newNode;
    }

    bool contains(uint key) {
        uint index = hash(key);

        Node *node = buckets[index];
        while (node != nullptr) {
            if (node->key == key)
                return true;

            node = node->next;
        }

        return false;
    }

    T& get(long key) {
        uint index = hash(key);

        Node* node = buckets[index];
        while (node != nullptr) {
            if (node->key == key) {
                return node->value;
            }
            node = node->next;
        }

        // Key not found
        throw std::out_of_range("Key not found");
    }
};
#endif //LAB7_HASHMAP_H
