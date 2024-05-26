#pragma once

#include <cstddef>
#include <cstdint>
template <typename T> class List {

  struct node {
    T d;
    node *next;
    node *prev;
  };

    class iterator{
    node* n;

    iterator& operator++(){
        n = n->next;
        return *this;
    }

    iterator& operator--(){
      n = n->prev;
      return *this;
    }
  };

  node *beg = nullptr; // deal: one node is kept empty
  node *last = nullptr; 
  size_t size = 0;

public:
  List() {

  }

  iterator begin(){
    iterator begin;
    begin.n = beg;
    return begin;
  }

  iterator end(){
    iterator end;
    end.n = nullptr;
    return end;
  }

  void push_back(const T &t) {
    node* n = reinterpret_cast<node *>(new uint8_t(sizeof(node)));
    n->d = T(t);
    n->next = nullptr;

    if(!beg){

      //first element
      beg = n;
      last = beg;
      n.prev = nullptr;

    } else {
      n.prev = last;
      last = n;
    }

    ++size;
  }

  void push_front(const T &t) {
    node n = reinterpret_cast<node *>(new uint8_t(sizeof(node)));
    n.d = T(t);
    n.prev = nullptr;

    if(!beg){
      beg = n;
      last = beg;
      n.prev = nullptr;
    } else {
      n.next = beg;
      beg = n;
    }
    ++size;
  }

  void pop_back() {
    last->d.~T();


    auto prev = last->prev;
    if(prev){
      prev->next = nullptr;
    }
    delete last;
    last = prev;

  }

  void pop_front() {
    beg->d.~T();
    
    auto next = beg->next;
    if(next){
      next->prev = nullptr;
    }
    delete beg;
    beg = next;
  }

  const T& back(){
    return last->d;
  }

  const T& front(){
    return beg->d;
  }


};
