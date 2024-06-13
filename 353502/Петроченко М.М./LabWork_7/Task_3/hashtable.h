//
// Created by acryoz on 26.05.24.
//

#include <cstddef>
#include <cstdint>
#include <stdexcept>

template <typename V>
class HashTable {
   protected:
    const uint64_t hashing_factor1 = 0xbf58476d1ce4e5b9;
    const uint64_t hashing_factor2 = 0x94d049bb133111eb;

    struct Node {
        const uint64_t key;
        V value;
        Node* next;

        Node(uint64_t key, const V& val, Node* next)
            : key(key), value(val), next(next) {}
    };

    uint64_t size;
    Node** stacks;

    uint64_t hash(uint64_t x) {
        x = (x ^ (x >> 30)) * hashing_factor1;
        x = (x ^ (x >> 27)) * hashing_factor2;
        x = x ^ (x >> 31);
        return x;
    }

   public:
    HashTable(uint64_t size) {
        this->size = size;
        this->stacks = new Node*[size];
        for (size_t i = 0; i < size; ++i) {
            this->stacks[i] = nullptr;
        }
    }

    void erase(uint64_t key) {
        uint64_t index = this->hash(key) % this->size;
        Node* stack = this->stacks[index];
        Node*& prev = this->stacks[index];
        while (stack != nullptr) {
            if (stack->key == key) {
                prev = stack->next;
                delete stack;
                return;
            }
            prev = stack->next;
            stack = stack->next;
        }
    }

    void clear() {
        for (size_t i = 0; i < size; ++i) {
            Node* stack = this->stacks[i];
            while (stack != nullptr) {
                Node* next = stack->next;
                delete stack;
                stack = next;
            }
            this->stacks[i] = nullptr;
        }
    }

    void insert(uint64_t key, const V& val) {
        this->erase(key);
        uint64_t index = this->hash(key) % this->size;
        Node* new_node = new Node(key, val, this->stacks[index]);
        this->stacks[index] = new_node;
    }

    V& get(uint64_t key) {
        uint64_t index = this->hash(key) % this->size;
        Node* stack = this->stacks[index];
        while (stack != nullptr) {
            if (stack->key == key) {
                return stack->value;
            }
            stack = stack->next;
        }
        throw new std::invalid_argument("No such key");
    }

    bool contains(uint64_t key) {
        try {
            this->get(key);
        } catch (std::invalid_argument) {
            return false;
        }
        return true;
    }
};
