#ifndef ITERATOR_LAB4
#define ITERATOR_LAB4
#include <cstddef>

template<typename T>
class BaseIterator{
public:
    explicit BaseIterator<T>(T* ptr);
protected:
    T* ptr;
   
public:
    T operator*();
    T operator*() const;
    bool operator==(const BaseIterator<T>&) const;
    bool operator!=(const BaseIterator<T>&) const;
    BaseIterator<T> operator+(size_t n);

    template<typename U> friend class Vector;
};

template<typename T>
class StraightIterator : public BaseIterator<T>{
    
public:
    StraightIterator<T>(T* ptr_);
    StraightIterator<T>& operator++();
    StraightIterator<T> operator++(int);
};

template<typename T>
class RevIterator : public BaseIterator<T>{
public:
    RevIterator<T>(T* ptr_);
    RevIterator<T>& operator++();
    RevIterator<T> operator++(int);
};

//---***---


template<typename T>
BaseIterator<T>::BaseIterator(T* ptr_) : ptr(ptr_){};

template<typename T>
BaseIterator<T> BaseIterator<T>::operator+(size_t n){
    BaseIterator<T> it;
    it.ptr+=n;
    return it;
}


template<typename T>    
T BaseIterator<T>::operator*(){
    return *ptr;
}

template<typename T>
T BaseIterator<T>::operator*() const{
    return *ptr;
}

template<typename T>
bool BaseIterator<T>::operator==(const BaseIterator<T>& other) const{
    return this->ptr == other.ptr;
}

template<typename T>
bool BaseIterator<T>::operator!=(const BaseIterator<T>& other) const{
    return this->ptr != other.ptr;
}



//---***---

template<typename T>
StraightIterator<T>::StraightIterator(T* ptr_) : BaseIterator<T>(ptr_) {}

template<typename T>
StraightIterator<T>& StraightIterator<T>::operator++(){
    ++BaseIterator<T>::ptr;
    return *this;
}

template<typename T>
StraightIterator<T> StraightIterator<T>::operator++(int){
    StraightIterator<T> tmp = *this;
    ++BaseIterator<T>::ptr;
    return tmp;
}

//---***---

template<typename T>
RevIterator<T>::RevIterator(T* ptr_) : BaseIterator<T>(ptr_) {}

template<typename T>
RevIterator<T>& RevIterator<T>::operator++(){
    --BaseIterator<T>::ptr;
    return *this;
}

template<typename T>
RevIterator<T> RevIterator<T>::operator++(int){
    RevIterator<T> tmp = *this;
    --BaseIterator<T>::ptr;
    return tmp;
}

#endif


