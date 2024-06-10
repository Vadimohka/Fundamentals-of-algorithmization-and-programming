#ifndef VECTOR_LAB4
#define VECTOR_LAB4

#include <stdexcept>
#include <limits>
#include <algorithm>

#include "vector_iterator.h"

template<typename T>
class Vector {

    using iterator = StraightIterator<T>;
    using const_iterator = const StraightIterator<T>;
    using rev_iterator = RevIterator<T>;
    using const_rev_iterator = const RevIterator<T>;

private:
    T *data_ = nullptr;
    size_t reserved_;
    size_t size_;
    const size_t size_update = 64;


public:
    explicit Vector(size_t);
    Vector(Vector<T>&);
    Vector();
    ~Vector();

    int size() const;
    int capacity() const;
    bool empty() const;
    size_t max_size() const;

    const T& back() const;
    const T& front() const;
    const T* data() const;

    void resize(size_t sz);
    void reserve(size_t sz);

    void push_back(const T& el);

    template<typename... Types>
    void emplace_back(Types... args);

    void insert(size_t it, const T& el);

    template<typename... Types>
    void emplace(size_t ind, Types... args);

    void pop_back();


    void clear();
    void erase(int);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    rev_iterator rbegin();
    rev_iterator rend();
    // const_rev_iterator crbegin();
    // const_rev_iterator crend();


    T& operator [](size_t x);
    const T& operator [](size_t x) const;
    T& at(size_t i);
    const T& at(size_t i) const;

    Vector<T>& operator=(const Vector<T>& a);
};


template<typename T>
Vector<T>::Vector(Vector<T> & v) : size_(v.size_), data_(new T[v.size_]), reserved_(v.size_)
{
    for(int i = 0; i < v.size_; i++){
        data_[i] = v.data_[i];
    }
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin(){
    iterator iter (data_);
    return iter;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end(){
    const_iterator iter (data_ + size_);
    return iter;
}


template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    const_iterator iter(data_);
    return iter;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    const_iterator iter(data_ + size_);
    return iter;
}


template<typename T>
typename Vector<T>::rev_iterator Vector<T>::rbegin() {
    rev_iterator iter(data_ + size_ - 1);
    return iter;
}

template<typename T>
typename Vector<T>::rev_iterator Vector<T>::rend() {
    rev_iterator iter(data_ - 1);
    return iter;
}

template<typename T>
Vector<T>::Vector(size_t reserve) {
    this->data_ = new T[reserve];
    this->reserved_ = reserve;
    this->size_ = 0;
}

template<typename T>
Vector<T>::Vector() {
    this->data_ = new T[size_update];
    this->reserved_ = size_update;
    this->size_ = 0;
}

template<typename T>
Vector<T>::~Vector() {
    this->clear();
}


template<typename T>
int Vector<T>::size() const {
    return size_;
}

template <typename T>
int Vector<T>::capacity() const {
    return reserved_;
}


template <typename T>
const T& Vector<T>::front() const {
    if(size_ == 0){
        throw std::runtime_error("The vector is empty. There is no front element");
    }
    return data_[0];
}

template <typename T>
const T& Vector<T>::back() const {
    if(size_ == 0){
        throw std::runtime_error("The vector is empty. There is no back element");
    }
    return data_[size_-1];
}

template <typename T>
const T* Vector<T>::data() const {
    return data_;

}

template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
size_t Vector<T>::max_size() const
{
    return std::numeric_limits<uintptr_t>::max() / sizeof(T);
}


template<typename T>
T& Vector<T>::operator[](size_t x){
    return data_[x];
}

template<typename T>
const T& Vector<T>::operator[](size_t x) const{
    return data_[x];
}

template<typename T>
T& Vector<T>::at(size_t x){
    if(x >= size_){
        throw std::invalid_argument("Index out of range");
    }
    return data_[x];
}

template<typename T>
void Vector<T>::reserve(size_t new_sz)
{
    if(size_ >= new_sz){
        return;
    } else {
        T *new_data = new T[new_sz];
        auto dataMaxInd = std::min(new_sz, size_);
        for(int i = 0; i < dataMaxInd; ++i){
            new_data[i] = data_[i];
        }

        delete [] data_;
        data_ = new_data;
        size_ = dataMaxInd;
        reserved_ = new_sz;
    }
}

template<typename T>
void Vector<T>::resize(size_t sz)
{
    size_t oldSize = this->size_;
    reserve(sz);
    if(this->size_ > oldSize){
        for(int i = oldSize; i < size_; ++i){
            data_[i] = new T();
        }
    }

}

template<typename T>
void Vector<T>::push_back(const T& el) {
    if (this->size_ == this->reserved_) {
        auto oldSize = size_;
        reserve(reserved_ + size_update);
        data_[oldSize] = el;
    } else {
        this->data_[this->size_] = el;
        this->size_++;
    }
}

template<typename T>
template<typename... Types>
void Vector<T>::emplace_back(Types... args){
    T t(std::forward<Types>(args)...);
    push_back(t);
}

template<typename T>
template<typename... Types>
void Vector<T>::emplace(size_t ind, Types... args){
    T t(std::forward<Types>(args)...);
    insert( ind, t);
}

template<typename T>
void Vector<T>::insert(size_t it, const T& el){
    reserve(size_ + 1);
    size_++;

    for(auto i = size_-1; i > it; i--){
        data_[i] = data_[i-1];
    }
    data_[it] = el;
}



template<typename T>
void Vector<T>::pop_back(){
    if(size_ == 0){
        return;
    }
    size_ -= 1;
    if(size_ && reserved_ / size_ > 2.){
        reserve(size_);
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &a) {
    if(this == &a){
        return *this;
    }

    if(a.size_ <= this->reserved_){
        for(int i = 0; i < a.size_; i++){
            data_[i] = a.data_[i];
        }
        size_ = a.size_;
        return *this;
    }
    else{

        T* new_data = new T[a.size_];
        for(int i = 0; i < a.size_; ++i){
            new_data[i] = a.data_[i];
        }

        delete[] this->data_;
        data_ = new_data;
        size_ = a.size_;
        reserved_ = a.size_;
        return *this;
    }
}


template<typename T>
void Vector<T>::erase(int x){
    for(int i = x; i < size_-1; i++){
        data_[i] = data_[i+1];
    }
    size_--;
}

template<typename T>
void Vector<T>::clear() {
    if(this->data_){
        delete[] this->data_;
    }
    this->data_ = nullptr;
    this->size_ = 0;
    this->reserved_ = 0;
}

#endif