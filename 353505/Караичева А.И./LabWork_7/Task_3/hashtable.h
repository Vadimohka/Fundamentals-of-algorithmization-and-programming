#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename T> class HashTable {

protected:

    const long UNIHASH_P = 65519;

    struct Entry {
        long key;
        Entry *next;
        T val;

        Entry(long key, Entry *next, const T &val)
            : key(key), next(next), val(val) {}
    };

    size_t hash(long key) { return ((hash_a * key + hash_b) % UNIHASH_P) % size; }

    void init(size_t size) {
        this->size = size;
        entries = new Entry *[size];
        for (int i = 0; i < size; i++) {
            entries[i] = nullptr;
        }

        hash_a = (rand() % (UNIHASH_P - 1) + 1);
        hash_b = rand() % UNIHASH_P;
    }

    void fronAnother(const HashTable &another) {
        size = another.size;
        entries = new Entry *[size];

        hash_a = another.hash_a;
        hash_b = another.hash_b;

        for (int i = 0; i < size; i++) {
            Entry *entr = another.entries[i];
            entries[i] = nullptr;
            while (entr != nullptr) {
                insert(entr->key, entr->val);
                entr = entr->next;
            }
        }
    }

public:
    HashTable(size_t size) { init(size); }

    HashTable(const HashTable &another) { fronAnother(another); }

    HashTable &operator=(const HashTable &another) {
        clear();
        delete[] entries;

        fronAnother(another);
        return *this;
    }

    HashTable(HashTable &&another) {
        size = another.size;
        entries = another.entries;
        hash_a = another.hash_a;
        hash_b = another.hash_b;

        another.init(size);
    }

    void clear() {
        for (int i = 0; i < size; i++) {
            Entry *entr = entries[i];
            while (entr != nullptr) {
                Entry *next = entr->next;
                delete entr;
                entr = next;
            }
            entries[i] = nullptr;
        }
    }

    ~HashTable() {
        clear();
        delete[] entries;
    }

    void insert(long key, const T &value) {

        remove(key);

        size_t index = hash(key);
        Entry *newe = new Entry(key, entries[index], value);
        entries[index] = newe;
    }

    bool contains(long key) {
        size_t index = hash(key);
        int lim = size;
        Entry *entr = entries[index];
        while (entr != nullptr) {
            if (entr->key == key)
                return true;
            entr = entr->next;
        }

        return false;
    }

    T &get(long key) {
        size_t index = hash(key);
        int lim = size;
        Entry *entr = entries[index];
        while (entr != nullptr) {
            if (entr->key == key)
                return entr->val;
            entr = entr->next;
        }

        throw new std::invalid_argument("Key not found");
    }

    void remove(long key) {
        size_t index = hash(key);
        int lim = size;
        Entry *entr = entries[index];
        Entry **prev_ptr = &entries[index];
        while (entr != nullptr) {
            if (entr->key == key) {
                *prev_ptr = entr->next;
                delete entr;
                return;
            }
            prev_ptr = &entr->next;
            entr = entr->next;
        }
    }


protected:

    size_t size;
    Entry **entries;

    long long hash_a;
    long long hash_b;

};

#endif // HASHTABLE_H
