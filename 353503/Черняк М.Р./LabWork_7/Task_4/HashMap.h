#include <cstddef>
#include <cstdlib>
#include <memory>
#include <stdexcept>

template <typename V> class HashMap {
private:
    const long UNIHASH_P = 65519;

    struct Key {
        long key;
        bool taken;
    };

    size_t hash(long key) const {
        return (static_cast<size_t>(key) * hash_a + hash_b) % UNIHASH_P;
    }

    size_t probe(long key, size_t i) const {
        return (hash(key) + i) % size;
    }

    void init(size_t newSize) {
        size = newSize;
        collisions = 0;
        keys = new Key[size];
        std::fill(keys, keys + size, Key{false, {0}});

        values = static_cast<V*>(operator new[](size * sizeof(V)));
        std::uninitialized_fill_n(values, size, V{});

        hash_a = static_cast<size_t>(rand()) % (UNIHASH_P - 1) + 1;
        hash_b = static_cast<size_t>(rand()) % UNIHASH_P;
    }

    void fromAnother(const HashMap& other) {
        size = other.size;
        collisions = other.collisions;
        hash_a = other.hash_a;
        hash_b = other.hash_b;

        keys = new Key[size];
        std::uninitialized_copy(other.keys, other.keys + size, keys);

        values = static_cast<V*>(operator new[](size * sizeof(V)));
        for (size_t i = 0; i < size; ++i) {
            if (other.keys[i].taken) {
                new (&values[i]) V(other.values[i]);
            }
        }
    }

public:
    HashMap(size_t size) {
        init(size);
    }

    HashMap(const HashMap& other) {
        fromAnother(other);
    }

    HashMap& operator=(const HashMap& other) {
        if (this == &other) {
            return *this;
        }

        HashMap temp(other);
        swap(temp);
        return *this;
    }

    HashMap(HashMap&& other) noexcept {
        size = other.size;
        collisions = other.collisions;
        keys = other.keys;
        values = other.values;
        hash_a = other.hash_a;
        hash_b = other.hash_b;

        other.size = 0;
        other.collisions = 0;
        other.keys = nullptr;
        other.values = nullptr;
    }

    HashMap& operator=(HashMap&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        clear();
        delete[] keys;
        delete[] static_cast<unsigned char*>(values);

        size = other.size;
        collisions = other.collisions;
        keys = other.keys;
        values = other.values;
        hash_a = other.hash_a;
        hash_b = other.hash_b;

        other.size = 0;
        other.collisions = 0;
        other.keys = nullptr;
        other.values = nullptr;

        return *this;
    }

    void clear() {
        for (size_t i = 0; i < size; ++i) {
            if (keys[i].taken) {
                values[i].~V();
                keys[i].taken = false;
            }
        }
        collisions = 0;
    }

    ~HashMap() {
        clear();
        delete[] keys;
        delete[] (unsigned char *)values;
    }

    void insert(long key, const V& value) {
        size_t index, i = 0;
        while (true) {
            index = probe(key, i++);
            if (!keys[index].taken) {
                keys[index].key = key;
                keys[index].taken = true;
                new (&values[index]) V(value);
                ++collisions;
                return;
            }
            if (keys[index].key == key) {
                values[index] = value;
                return;
            }
            ++collisions;
            if (i == size) {
                return;
            }
        }
    }

    bool contains(long key) const {
        size_t index, i = 0;
        while (true) {
            index = probe(key, i++);
            if (!keys[index].taken) {
                return false;
            }
            if (keys[index].key == key) {
                return true;
            }
            if (i == size) {
                return false;
            }
        }
    }

    V& get(long key) {
        size_t index, i = 0;
        while (true) {
            index = probe(key, i++);
            if (!keys[index].taken) {
                throw std::invalid_argument("Key not found");
            }
            if (keys[index].key == key) {
                return values[index];
            }
            if (i == size) {
                throw std::invalid_argument("Key not found");
            }
        }
    }

    size_t getCollisionCount(bool reset) {
        size_t ret = collisions;
        if (reset) {
            collisions = 0;
        }
        return ret;
    }

private:
    size_t size;
    size_t collisions;
    Key *keys;
    V *values;

    long long hash_a;
    long long hash_b;
};
