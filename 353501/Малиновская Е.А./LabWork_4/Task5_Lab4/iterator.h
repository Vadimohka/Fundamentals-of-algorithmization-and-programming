#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>
template<typename T>
class Iterator
{
private:

    T *it;

public:

    explicit Iterator(T *t) : it(t){}

    ~Iterator() = default;

    const T *base() const {
        return it;
    }

    T &operator*() const {
        return *it;
    }

    T *operator->() const {
        return it;
    }

    Iterator operator++() {
        ++it;
        return *this;
    }

    Iterator &operator--() {
        --it;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp(*this);
        ++(*this);
        return temp;
    }

    Iterator operator--(int) {
        Iterator temp(*this);
        --(*this);
        return temp;
    }

    Iterator operator+(int n){
        return Iterator(it + n);
    }

    Iterator operator-(int n){
        return Iterator(it - n);
    }

    Iterator &operator+=(size_t n) {
        it += n;
        return *this;
    }

    Iterator &operator-=(size_t n) {
        it -= n;
        return *this;
    }

    T operator[](size_t n) {
        return it[n];
    }

    bool operator==(const Iterator& a) {
        return it == a.it;
    }

    bool operator !=(const Iterator& a) {
        return it != a.it;
    }



};


template<typename T>
class Rev_Iterator
{
private:

    T *it;

public:

    explicit Rev_Iterator(T *t) : it(t){}

    ~Rev_Iterator() = default;

    const T *base() const {
        return it;
    }

    T &operator*() const {
        return *it;
    }

    T *operator->() const {
        return it;
    }

    Rev_Iterator operator++() {
        --it;
        return *this;
    }

    Rev_Iterator &operator--() {
        ++it;
        return *this;
    }

    Rev_Iterator operator++(int) {
        Rev_Iterator temp(*this);
        --(*this);
        return temp;
    }

    Rev_Iterator operator--(int) {
        Rev_Iterator temp(*this);
        --(*this);
        return temp;
    }

    Rev_Iterator operator+(int n){
        return Rev_Iterator(it - n);
    }

    Rev_Iterator operator-(int n){
        return Rev_Iterator(it + n);
    }

    Rev_Iterator &operator+=(size_t n) {
        it -= n;
        return *this;
    }

    Rev_Iterator &operator-=(size_t n) {
        it += n;
        return *this;
    }

    T operator[](size_t n) {
        return it[n];
    }

    bool operator==(const Rev_Iterator& a) {
        return it == a.it;
    }


    bool operator !=(const Rev_Iterator& a) {
        return it != a.it;
    }



};
#endif // ITERATOR_H
