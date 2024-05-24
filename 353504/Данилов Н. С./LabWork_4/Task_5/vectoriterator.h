#pragma once

#include <cstddef>
#include <QString>
template<typename T>
class VectorIterator {
private:
   T *ptr;
public:
   VectorIterator(T *p) : ptr(p) {
       ptr = p;
   }

   VectorIterator<T> &operator++() {
       ++ptr;
       return *this;
   }

   VectorIterator<T> operator++(int) {
       VectorIterator<T> temp = *this;
       ++ptr;
       return temp;
   }

   VectorIterator<T> &operator--() {
       --ptr;
       return *this;
   }

   VectorIterator<T> operator--(int) {
       VectorIterator<T> temp = *this;
       --ptr;
       return temp;
   }

   T &operator*() {
       return *ptr;
   }

   bool operator==(const VectorIterator<T> &other) const {
       return ptr == other.ptr;
   }

   bool operator!=(const VectorIterator<T> &other) const {
       return ptr != other.ptr;
   }

   ptrdiff_t operator-(const VectorIterator<T> &other) const {
       return ptr - other.ptr;
   }

   ptrdiff_t operator+(const VectorIterator<T> &other) const {
       return ptr + other.ptr;
   }

   VectorIterator operator+(const int a) {
       VectorIterator<T> temp = *this;
       temp.ptr += a;
       return temp;
   }

   VectorIterator operator-(const int a) {
       VectorIterator<T> temp = *this;
       temp.ptr -= a;
       return temp;
   }

   QString toString () {
       return QString::number(std::uintptr_t(ptr));
   }
};
