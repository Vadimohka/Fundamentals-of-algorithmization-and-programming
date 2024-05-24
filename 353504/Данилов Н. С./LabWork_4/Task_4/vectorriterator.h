#pragma once

#include <cstddef>
#include <QString>
template<typename T>
class VectorRIterator {
private:
   T *ptr;
public:
   explicit VectorRIterator(T *p) : ptr(p) {
       ptr = p;
   }

   VectorRIterator<T> &operator++() {
       --ptr;
       return *this;
   }

   VectorRIterator<T> operator++(int) {
       VectorRIterator<T> temp = *this;
       --ptr;
       return temp;
   }

   VectorRIterator<T> &operator--() {
       ++ptr;
       return *this;
   }

   VectorRIterator<T> operator--(int) {
       VectorRIterator<T> temp = *this;
       ++ptr;
       return temp;
   }

   T &operator*() {
       return *ptr;
   }

   bool operator==(const VectorRIterator<T> &other) const {
       return ptr == other.ptr;
   }

   bool operator!=(const VectorRIterator<T> &other) const {
       return ptr != other.ptr;
   }

   ptrdiff_t operator-(const VectorRIterator<T> &other) const {
       return ptr - other.ptr;
   }

   ptrdiff_t operator+(const VectorRIterator<T> &other) const {
       return ptr + other.ptr;
   }

   VectorRIterator operator+(const int a) {
       VectorRIterator<T> temp = *this;
       temp.ptr -= a;
       return temp;
   }

   VectorRIterator operator-(const int a) {
       VectorRIterator<T> temp = *this;
       temp.ptr += a;
       return temp;
   }

   QString toString () {
       return QString::number(std::uintptr_t(ptr));
   }
};
