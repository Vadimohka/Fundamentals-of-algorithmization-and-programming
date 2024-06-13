//
// Created by acryoz on 26.05.24.
//

#ifndef LAB7_TASK4_HASHTABLE_H_
#define LAB7_TASK4_HASHTABLE_H_

#include <stddef.h>
#include <cstdint>
#include <stdexcept>

template <typename V>
class HashTable2 {
   private:
    static constexpr uint64_t PRIME = (2 << 31) - 1;
    size_t sz;
    size_t max_sz;
    uint8_t* states;  //0 - free, 1 - taken, 2 - deleted, not free
    uint64_t* keys;
    uint64_t hashing_factor1;
    uint64_t hashing_factor2;
    uint64_t collisions;
    V* values;

    size_t hash(uint64_t key) {
        return ((hashing_factor1 * key + hashing_factor2) % PRIME) % this->sz;
    }

   public:
    HashTable2(uint64_t new_size) {
        this->sz = new_size;
        this->collisions = 0;
        this->states = new uint8_t[new_size];
        this->keys = new uint64_t[new_size];
        for (int i = 0; i < new_size; i++) {
            this->states[i] = 0;
        }
        this->values = reinterpret_cast<V*>(new uint8_t[new_size * sizeof(V)]);

        this->hashing_factor1 = (rand() % (PRIME - 1) + 1);
        this->hashing_factor2 = rand() % PRIME;
    }

    size_t size() { return this->sz; }

    size_t max_size() { return this->max_sz; }

    void clear() {
        for (size_t i = 0; i < this->sz; ++i) {
            if (states[i] != 0) {
                values[i]->~V();
                states[i] = 0;
            }
        }
        this->sz = 0;
    }

    V& get(uint64_t key) {
        size_t index = this->hash(key);
        size_t iterations_limit = this->sz;
        while (this->states[index] != 0) {
            if (this->keys[index] == key) {
                return this->values[index];
            }
            index++;
            if (index > this->sz) {
                index = 0;
            }
            iterations_limit--;
            if (iterations_limit == 0) {
                break;
            }
        }
        throw new std::invalid_argument("No such key");
    }

    bool contains(uint64_t key) {
        size_t index = this->hash(key);
        size_t iterations_limit = this->sz;
        while (this->states[index] != 0) {
            if (this->keys[index] == key) {
                return true;
            }
            index++;
            if (index > this->sz) {
                index = 0;
            }
            iterations_limit--;
            if (iterations_limit == 0) {
                break;
            }
        }
        return false;
    }

    uint64_t collisionCount() { return this->collisions; }

    void insert(uint64_t key, const V& value) {
        size_t index = this->hash(key);
        size_t iterations_limit = this->sz;
        while (this->states[index] != 0) {
            if (this->keys[index] == key) {
                break;
            }
            ++this->collisions;
            index++;
            if (index > this->sz) {
                index = 0;
            }
            iterations_limit--;
            if (iterations_limit == 0) {
                return;
            }
        }
        this->keys[index] = key;
        this->states[index] = 1;
        new (this->values + index) V(value);
    }

    void remove(uint64_t key) {
        size_t index = this->hash(key);
        size_t iterations_limit = this->sz;
        while (this->states[index] != 0) {
            if (this->keys[index] == key) {
                this->values[index].~V();
                this->sz -= 1;
                return;
            }
            index++;
            if (index > this->sz) {
                index = 0;
            }
            iterations_limit--;
            if (iterations_limit == 0) {
                return;
            }
        }
    }

    void resetCollisionCount() { this->collisions = 0; }

    ~HashTable2() {
        for (size_t i = 0; i < this->sz; ++i) {
            if (this->states[i] != 0) {
                this->values[i].~V();
            }
        }
        delete[] reinterpret_cast<uint8_t*>(this->values);
        delete[] this->keys;
        delete[] this->states;
    }
};
#endif  //LAB7_TASK4_HASHTABLE_H_
