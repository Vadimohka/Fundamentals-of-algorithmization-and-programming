#ifndef VECTOR_H
#define VECTOR_H
#include "iterator.h"
#include<iostream>
template <typename T>
class Vector
{
private:
    T iter=new iterator<T>;
    T *arr;
    std::size_t size;
public:
    Vector(){
            arr=nullptr;
            size=0;
    };
    Vector assign_m(Vector a){
        Vector <int> v  = a;
        ~Vector();
        return a;
    };
    std::size_t* at_m(std::size_t k){
        if(size<k) return 0;
        else return arr=arr+(sizeof(std::size_t)*k);
    }
    std::size_t* back(){
        return arr+sizeof(std::size_t)*size;
    }
    iterator<T> begin(){
        iterator <std::size_t> k=arr;
        return k;
    }
    long long capacity(){
        return size;
    }
    const iterator<T> cbegin(){
        const iterator <std::size_t> k=arr;
        return k;
    }
    void clear(){
          ~Vector();
    }
    long long *data(){
        return arr;
    }
    void emplace(std::size_t s,std::size_t k){
        if(size<s) return;
        arr+=sizeof(std::size_t);
        arr[s-1]=k;
    }
    void emplace_back(std::size_t s){
        arr+=sizeof(std::size_t);
        arr[size-1]=s;
    }
    bool empty(){
        if(size==0) return true;
        else return false;
    }
    iterator<T> end(){
        iterator <std::size_t> k=arr+sizeof(std::size_t)*size;
        return k;
    }
    void erase(std::size_t t){
        std::size_t l=arr[size-1];
        arr[size-1]=arr[t-1];
        arr-=arr+sizeof(std::size_t);
    }
    std::size_t *front(){
        return arr;
    }
    void insert(std::size_t s){
        arr+=sizeof(std::size_t);
        arr[size-1]=s;
    }
    long long max_size(){
        return size;
    }
    void pop_back(){
        arr-=arr+sizeof(std::size_t);
    }
    void push_back(std::size_t s){
        arr+=sizeof(std::size_t);
        arr[size-1]=s;
    }
    iterator <T> rbegin(){
        return arr+sizeof(size_t)*size;
    }
    iterator<T> rend(){
        return arr-sizeof(size_t)*size;
    }
    void reserve(){
        size+=sizeof(size_t);
    }
    void resize(std::size_t a){
        size=a;
    }
    long long size_m(){
        return size;
    }
    void swap(size_t a1,size_t a2){
        std::swap(a1,a2);
    }
    ~Vector(){
        delete this;
    };
};

#endif // VECTOR_H
