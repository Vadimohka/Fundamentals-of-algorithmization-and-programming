
#ifndef TASK4_ITERATOR_H
#define TASK4_ITERATOR_H
#include <vector>
template<typename T>
class Iterator{
    T* ptr;
public:
    explicit Iterator(T* point){
        ptr = point;
    }
    Iterator &operator++() {
        ++ptr;
        return *this;
    }
    Iterator operator++(int) {
        ptr++;
        return *this;
    }
    T &operator*(){
        return *ptr;
    }
    Iterator operator+(int a){
        return Iterator(ptr + a);
    }
    Iterator operator-(int a){
        return Iterator(ptr + a);
    }
    Iterator &operator--(){
        --ptr;
        return *this;
    }
    Iterator operator--(int) {
        ptr--;
        return *this;
    }
    bool operator==(Iterator &other){
        return this == other;
    }
    Iterator operator+=(int val){
        this += val;
        return *this;
    }
    Iterator operator-=(int val){
        this -= val;
        return *this;
    }
    bool operator!=(Iterator &other){
        return this != other;
    }
};
template<typename T>
class ReverseIterator
{
    T *iter;

public:
    explicit ReverseIterator(T *temp)
    {
        iter = temp;
    }

    ~ReverseIterator();

    const T *base() const
    {
        return iter;
    }

    T &operator*() const
    {
        return *iter;
    }

    T *operator->() const
    {
        return iter;
    }

    ReverseIterator &operator++()
    {
        --iter;
        return *this;
    }

    ReverseIterator &operator--()
    {
        ++iter;
        return *this;
    }

    ReverseIterator &operator++(int)
    {
        return Iterator(iter--);
    }

    ReverseIterator &operator--(int)
    {
        return Iterator(iter++);
    }

    ReverseIterator operator+(int value)
    {
        return Iterator(iter - value);
    }

    ReverseIterator operator-(int value)
    {
        return Iterator(iter + value);
    }

    ReverseIterator &operator+=(int value)
    {
        iter -= value;
        return *this;
    }

    ReverseIterator &operator-=(int value)
    {
        iter += value;
        return *this;
    }

    T operator[](int index)
    {
        return iter[index];
    }

    bool operator==(ReverseIterator &other)
    {
        return iter == other.operator->();
    }

    bool operator!=(ReverseIterator &other)
    {
        return iter != other.operator->();
    }
};
#endif //TASK4_ITERATOR_H
