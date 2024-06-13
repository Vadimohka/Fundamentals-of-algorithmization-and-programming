#ifndef LABWORK_7_DEQUE_H
#define LABWORK_7_DEQUE_H

#include <cstdint>
#include <new>
#include <utility>
#include "QDebug"

static const int block_size = 4;
static const int factor_of_alloc = 2;


template<typename T>
class Deque {
    unsigned long long sz;
    long long count_of_blocks;
    long long begin_block_index;
    long long end_block_index;
    short begin_index_in_block = block_size - 1;
    short end_index_in_block = 0;
    T *begin_ptr;
    T *end_ptr;
    T **blocks_arr;

    void resize();

    class iterator {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T *;
        using reference = T&;
        T *main_ptr;
        Deque<T> *container;
        long long block_index;
        short index_in_block;
    public:

        iterator(Deque<T> *parent, pointer ptr_to_element, long long blck_index, short index_in_blck) {
            container = parent;
            main_ptr = ptr_to_element;
            block_index = blck_index;
            index_in_block = index_in_blck;
        }

        friend bool operator==(const iterator a, const iterator b) {
            return a.main_ptr == b.main_ptr;
        }

        friend bool operator!=(const iterator a, const iterator b) {
            return b.block_index != a.block_index || a.index_in_block != b.index_in_block;
        }

        reference operator*() const {
            return *main_ptr;
        }

        iterator &operator++() {
            if (block_size - 1 > index_in_block) {
                index_in_block++;
                main_ptr = &container->blocks_arr[block_index][index_in_block];
            } else {
                if (block_index != container->count_of_blocks - 1) {
                    block_index++;
                } else {
                    block_index = 0;
                }
                index_in_block = 0;
                main_ptr = &(container->blocks_arr[block_index][index_in_block]);
            }
            return *this;
        }

        iterator operator++(T) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        };
    };

public:
    Deque();

    ~Deque();

    long long size();

    bool empty();

    void push_back(const T &object);

    void push_front(const T &object);

    void pop_back();

    void pop_front();

    void clear();

    iterator begin();

    iterator end();

};

template<typename T>
typename Deque<T>::iterator Deque<T>::end() {
    return Deque::iterator(this, end_ptr, end_block_index, end_index_in_block);
}

template<typename T>
typename Deque<T>::iterator Deque<T>::begin() {
    return Deque::iterator(this, begin_ptr, begin_block_index, begin_index_in_block);
}

template<typename T>
Deque<T>::~Deque() {
    for (int i = 0; i < count_of_blocks; i++) {
        delete[] blocks_arr[i];
    }
    delete[] blocks_arr;
}

template<typename T>
void Deque<T>::clear() {
    for (int i = 0; i < count_of_blocks; i++) {
        delete[] blocks_arr[i];
    }
    blocks_arr = new T* [factor_of_alloc];
    count_of_blocks = factor_of_alloc;
    for (int i = 0; i < factor_of_alloc; i++) {
        blocks_arr[i] = reinterpret_cast<T *> (new unsigned char[block_size * sizeof(T)]);
    }
    begin_ptr = (blocks_arr[factor_of_alloc - 1] + 3);

    end_ptr = blocks_arr[0];

    sz = 0;
    begin_block_index = count_of_blocks - 1;
    end_block_index = 0;
}

template<typename T>
void Deque<T>::pop_front() {
    sz--;
    if (&blocks_arr[end_block_index][0] < end_ptr) {
        end_index_in_block--;
        end_ptr = &blocks_arr[end_block_index][end_index_in_block];
        end_ptr->~T();
    }
    if (&blocks_arr[end_block_index][0] == end_ptr) {
        end_block_index--;
        end_index_in_block = block_size - 1;
        end_ptr = &blocks_arr[end_block_index][end_index_in_block];
        end_ptr->~T();
        if (begin_block_index == end_block_index) {
            clear();
        }
    }
}

template<typename T>
void Deque<T>::pop_back() {
    sz--;
    if (&blocks_arr[begin_block_index][3] > begin_ptr) {
        begin_index_in_block++;
        begin_ptr = &blocks_arr[begin_block_index][begin_index_in_block];
        begin_ptr->~T();
    }
    if (&blocks_arr[begin_block_index][3] == begin_ptr) {
        begin_block_index++;
        begin_index_in_block = 0;
        begin_ptr = &blocks_arr[begin_block_index][begin_index_in_block];
        begin_ptr->~T();
        if (begin_block_index == end_block_index) {
            clear();
        }
    }
}

template<typename T>
void Deque<T>::push_front(const T &object) {
    sz++;
    if (block_size - 1 > end_index_in_block) {
        try {
            end_ptr = new(end_ptr) T(object);
        }
        catch (...) {
            end_ptr->~T();
            sz--;
            throw (std::bad_alloc());
        }
        end_index_in_block++;
        end_ptr = &blocks_arr[end_block_index][end_index_in_block];
    } else if (block_size - 1 == end_index_in_block) {
        try {
            end_ptr = new(end_ptr) T(object);
        }
        catch (...) {
            end_ptr->~T();
            end_block_index--;
            if (end_block_index == count_of_blocks) {
                end_block_index = 0;
            }
            end_ptr = &blocks_arr[end_block_index][block_size - 1];
            sz--;
            throw (std::bad_alloc());
        }
        if (end_block_index != count_of_blocks - 1) {
            end_block_index++;
        } else {
            end_block_index = 0;
        }
        end_index_in_block = 0;
        if (end_block_index == begin_block_index) {
            end_block_index--;
            resize();
        }
        end_ptr = &blocks_arr[end_block_index][0];
    }
}

template<typename T>
void Deque<T>::push_back(const T &object) {
    sz++;
    if (0 < begin_index_in_block) {
        begin_index_in_block--;
    } else if (0 == begin_index_in_block) {
        if (begin_block_index != 0) {
            begin_block_index--;
        } else {
            begin_block_index = count_of_blocks - 1;
        }
        begin_index_in_block = block_size - 1;
        if (end_block_index == begin_block_index) {
            begin_block_index++;
            resize();
        }
    }

    begin_ptr = &blocks_arr[begin_block_index][begin_index_in_block];
        try {
            begin_ptr = new(begin_ptr) T(object);
        }
        catch (...) {
            if (block_size - 1 > begin_index_in_block) {
                begin_index_in_block++;
            } else if (block_size - 1 == begin_index_in_block) {
                if (begin_block_index != count_of_blocks - 1) {
                    begin_block_index++;
                } else {
                    begin_block_index = 0;
                }
                begin_index_in_block = 0;
            }
            begin_ptr->~T();

            sz--;
            throw (std::bad_alloc());
        }
}

template<typename T>
void Deque<T>::resize() {

    int capacity = count_of_blocks * factor_of_alloc;
    T** new_blocks_arr = new T* [capacity];
    for (int i = begin_block_index; i < count_of_blocks; i++) {
        new_blocks_arr[i - begin_block_index] = blocks_arr[i];
    }
    for (int i = 0; i < begin_block_index; i++) {
        new_blocks_arr[count_of_blocks - begin_block_index + i] = blocks_arr[i];
    }
    for (int i = count_of_blocks; i < capacity; i++) {
        new_blocks_arr[i] = new T[block_size];
    }

//    for (int i = begin_block_index; i < count_of_blocks; i++) {
//        new_blocks_arr[i - begin_block_index] = blocks_arr[i];
//    }
//    for (int i = 0; i < capacity - count_of_blocks; i++) {
//        new_blocks_arr[count_of_blocks - begin_block_index + i] = blocks_arr[i];
//    }
    std::swap(new_blocks_arr, blocks_arr);
    begin_block_index = 0;
    begin_index_in_block = 0;
    end_block_index = end_block_index + (count_of_blocks - begin_block_index - 1);

    count_of_blocks = capacity;
    delete[] new_blocks_arr;
}

template<typename T>
bool Deque<T>::empty() {
    return sz == 0;
}

template<typename T>
long long Deque<T>::size() {
    return sz;
}
+


#endif //LABWORK_7_DEQUE_H
