//
// Created by acryoz on 26.05.24.
//

#include <cstddef>
#include <cstdint>

template <typename T>
class Deque {
    static const size_t BUCKET_SIZE = 512;
    static const size_t SIZE_MULTIPLIER = 2;

    struct DequeIndex {
        size_t block;
        size_t index;

        bool operator==(DequeIndex& other) {
            return this->block == other.block && this->index == other.index;
        }
    };

   public:
    class Iterator {
        friend class Deque<T>;
        Deque<T>* container;
        size_t index;

        Iterator(Deque<T>* parent, size_t index)
            : container(parent), index(index) {}

       public:
        Iterator& operator++() {
            ++this->index;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            this->index++;
            return tmp;
        }

        Iterator& operator--() {
            --this->index;
            return *this;
        }

        Iterator operator--(int) {
            Iterator tmp = *this;
            this->index--;
            return tmp;
        }

        T& operator*() {
            DequeIndex internal_index = this->container->indexAt(index);
            return this->container
                ->buckets[internal_index.block][internal_index.index];
        }

        T* operator->() {
            DequeIndex internal_index = this->container->indexAt(index);
            return &this->container
                        ->buckets[internal_index.block][internal_index.index];
        }

        bool operator==(const Iterator& other) {
            return this->index == other.index;
        }

        bool operator!=(const Iterator& other) {
            return this->index != other.index;
        }
    };

    Iterator begin() { return Iterator(this, 0); }

    Iterator end() { return Iterator(this, sz); }

    Deque() {
        this->buckets = new T*[2];
        for (int i = 0; i < 2; ++i) {
            this->buckets[i] =
                reinterpret_cast<T*>(new uint8_t[sizeof(T) * BUCKET_SIZE]);
        }
        this->capacity = 2;
        this->sz = 0;
        this->first.block = 0;
        this->first.index = 0;
    }

    ~Deque() {
        while (!this->empty()) {
            this->pop_back();
        }
        delete[] this->buckets;
    }

    void clear() {
        while (!this->empty()) {
            this->pop_back();
        }
    }

    void push_back(const T& elem) {
        if (this->full()) {
            this->grow();
        }
        ++this->sz;
        auto new_index = this->indexAt(sz - 1);
        new (&this->buckets[new_index.block][new_index.index]) T(elem);
    }

    void push_front(const T& elem) {
        if (this->full()) {
            this->grow();
        }
        ++this->sz;
        --this->first.index;
        if (this->first.index == SIZE_MAX) {
            this->first.index = BUCKET_SIZE - 1;
            --this->first.block;
        }
        if (this->first.block == SIZE_MAX) {
            this->first.block = this->capacity - 1;
        }
        new (&this->buckets[this->first.block][this->first.index]) T(elem);
    }

    void pop_back() {
        auto last = this->indexAt(sz - 1);
        this->buckets[last.block][last.index].~T();
        --this->sz;
    }

    void pop_front() {
        this->buckets[this->first.block][this->first.index].~T();
        --this->sz;
        ++this->first.index;
        if (this->first.index == BUCKET_SIZE) {
            this->first.index = 0;
            this->first.block++;
        }
        if (this->first.block == this->capacity) {
            this->first.block = 0;
            this->first.index = 0;
        }
    }

    const T& front() const { return this->buckets[first.block][first.index]; }

    const T& back() const { return this[this->sz - 1]; }

    const T& operator[](size_t index) const {
        auto real_index = this->indexAt(index);
        return this->buckets[real_index.block][real_index.index];
    }

    T& operator[](size_t index) {
        auto real_index = this->indexAt(index);
        return this->buckets[real_index.block][real_index.index];
    }

    size_t size() const { return this->sz; }

    bool empty() const { return this->sz == 0; }

   private:
    void grow() {
        size_t new_size = this->capacity * SIZE_MULTIPLIER;
        T** new_buckets = new T*[new_size];

        auto used_blocks = sz / BUCKET_SIZE;

        size_t j = 0;
        size_t i = first.block;
        while (j <= used_blocks) {
            new_buckets[j] = this->buckets[i];
            i = (i + 1) % this->capacity;
            ++j;
        }
        for (; j < new_size; ++j) {
            new_buckets[j] =
                reinterpret_cast<T*>(new uint8_t[BUCKET_SIZE * sizeof(T)]);
        }

        delete[] this->buckets;
        this->buckets = new_buckets;
        this->capacity = new_size;
        this->first.block = 0;
    }

    bool full() { return sz == capacity * BUCKET_SIZE - 1; }

    DequeIndex indexAt(size_t i) const {
        auto total_index =
            (this->first.block * BUCKET_SIZE + this->first.index + i);
        return { (total_index / BUCKET_SIZE) % this->capacity,
                 total_index % BUCKET_SIZE };
    }

    T** buckets;

    size_t capacity;
    DequeIndex first;
    size_t sz;
};
