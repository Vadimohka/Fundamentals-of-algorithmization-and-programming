#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#define N 32

template<typename T>
class Iterator;

template <typename T>
class Deque
{
public:
    using iterator = Iterator<T>;
    Deque();
    ~Deque();
    const T &operator[](size_t index) const;
    T &operator[](size_t index);
    const T &at(size_t index) const;
    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    int front();
    int back();
    bool empty();
    int size();
    void clear();
    void print();
    std::string to_string();
private:
    size_t size_;
    size_t capacity_;
    T** bucket_;
    size_t begin_index; // begin index in the bucket
    size_t begin_;

    size_t end_index; // end index in the bucket
    size_t end_;
    void resize();
};

template <typename T>
Deque<T>::Deque()
{
    size_ = 0;
    capacity_ = N;
    bucket_ = reinterpret_cast<T**>(new char[sizeof(T*) * N]);
    for (size_t i = 0; i < N; i++)
    {
        bucket_[i] = reinterpret_cast<T*>(new char[sizeof(T) * N]);
    }
    begin_index = 0;
    begin_ = 0;
    end_index = 0;
    end_ = 0;
}

template <typename T>
Deque<T>::~Deque()
{
    for (size_t i = 0; i < N; i++)
    {
        delete[] bucket_[i];
    }
    delete[] bucket_;
}

template <typename T>
void Deque<T>::resize()
{
    T** new_bucket = reinterpret_cast<T**>(new char[sizeof(T*) * capacity_ * 2]);
    for (size_t i = 0; i < capacity_ * 2; i++)
    {
        new_bucket[i] = reinterpret_cast<T*>(new char[sizeof(T) * N]);
    }
    for (size_t i = 0; i < size_; i++)
    {
        new_bucket[i / N][i % N] = bucket_[begin_index][begin_];
        begin_++;
        if (begin_ == N)
        {
            begin_ = 0;
            begin_index++;
        }
    }
    for (size_t i = 0; i < capacity_; i++)
    {
        delete[] bucket_[i];
    }
    delete[] bucket_;
    bucket_ = new_bucket;
    capacity_ *= 2;
    begin_index = 0;
    begin_ = 0;
    end_index = size_;
    end_ = 0;
}
template <typename T>
void Deque<T>::push_back(T value)
{
    if (size_ == capacity_)
    {
        resize();
    }
    bucket_[end_index][end_] = value;
    end_++;
    if (end_ == N)
    {
        end_ = 0;
        end_index++;
    }
    size_++;
}

template <typename T>
void Deque<T>::push_front(T value)
{
    if (size_ == capacity_)
    {
        resize();
    }
    if (begin_ == 0)
    {
        begin_ = N - 1;
        begin_index = begin_index == 0 ? capacity_ - 1 : begin_index - 1;
    }
    else
    {
        begin_--;
    }
    bucket_[begin_index][begin_] = value;
    size_++;
}

template <typename T>
void Deque<T>::pop_back()
{
    if (size_ == 0)
    {
        return;
    }
    if (end_ == 0)
    {
        end_index--;
        end_ = N - 1;
    }
    else
    {
        end_--;
    }
    size_--;
}

template <typename T>
void Deque<T>::pop_front()
{
    if (size_ == 0)
    {
        return;
    }
    begin_++;
    if (begin_ == N)
    {
        begin_index++;
        begin_ = 0;
    }
    size_--;
}

template <typename T>
int Deque<T>::front()
{
    return bucket_[begin_index][begin_];
}

template <typename T>
int Deque<T>::back()
{
    if (end_ == 0)
    {
        return bucket_[end_index - 1][N - 1];
    }
    return bucket_[end_index][end_ - 1];
}

template <typename T>
bool Deque<T>::empty()
{
    return size_ == 0;
}

template <typename T>
int Deque<T>::size()
{
    return size_;
}

template <typename T>
void Deque<T>::clear()
{
    size_ = 0;
    begin_index = 0;
    begin_ = 0;
    end_index = 0;
    end_ = 0;
}

template <typename T>
void Deque<T>::print()
{
    size_t local_begin_index = begin_index;
    size_t local_begin = begin_;
    for (size_t i = 0; i < size_; i++)
    {
        if(bucket_[local_begin_index] != nullptr)
        {
            std::cout << bucket_[local_begin_index][local_begin] << " ";
        }
        local_begin++;
        if (local_begin == N)
        {
            local_begin = 0;
            local_begin_index = (local_begin_index + 1) % capacity_;
        }
    }
    std::cout << std::endl;
}

template <typename T>
std::string Deque<T>::to_string()
{
    std::string str;
    size_t local_begin_index = begin_index;
    size_t local_begin = begin_;
    for (size_t i = 0; i < size_; i++)
    {
        if(bucket_[local_begin_index] != nullptr)
        {
            str += std::to_string(bucket_[local_begin_index][local_begin]) + " ";
        }
        local_begin++;
        if (local_begin == N)
        {
            local_begin = 0;
            local_begin_index = (local_begin_index + 1) % capacity_;
        }
    }
    return str;
}

template <typename T>
const T &Deque<T>::operator[](size_t index) const
{
    return bucket_[(begin_index + index / N) % capacity_][index % N];
}

template <typename T>
T &Deque<T>::operator[](size_t index)
{
    return bucket_[(begin_index + index / N) % capacity_][index % N];
}

template <typename T>
const T &Deque<T>::at(size_t index) const
{
    if (index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return bucket_[(begin_index + index / N) % capacity_][index % N];
}

//Random access iterator
template<typename T>
class Iterator
{
private:
    Deque<T> *deque;
    size_t index;

public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    Iterator(Deque<T> *deque, size_t index)
        : deque(deque)
        , index(index)
    {}

    T &operator*() { return deque[index]; }

    const T &operator*() const { return deque[index]; }

    Iterator operator++()
    {
        ++index;
        return *this;
    }

    Iterator operator--()
    {
        --index;
        return *this;
    }

    Iterator operator+(difference_type n) const { return DequeIterator(deque, index + n); }

    Iterator operator-(difference_type n) const { return DequeIterator(deque, index - n); }

    difference_type operator-(const Iterator &other) { return index - other.index; }

    bool operator==(const Iterator &other) const { return index == other.index; }

    bool operator!=(const Iterator &other) const { return index != other.index; }

    bool operator<(const Iterator &other) const { return index < other.index; }

    bool operator>(const Iterator &other) const { return index > other.index; }

    bool operator<=(const Iterator &other) const { return index <= other.index; }

    bool operator>=(const Iterator &other) const { return index >= other.index; }
};

#endif // DEQUE_H
