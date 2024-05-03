#include "myvec.h"
#include <limits>
#include <stdexcept>

// template<typename T>
// MyVec<T>::MyVec() : arr(nullptr), _size(0), _capacity(0)
// {}

// template<typename T>
// MyVec<T>::MyVec(size_t n)
// {
//     reserve(n);
//     for (size_t i = 0; i < n; i++)
//     {
//         new(arr + i) T();
//     }
// }

// template<typename T>
// MyVec<T>::MyVec(MyVec<T> const &tmp)
// {
//     _size = tmp.size_;
//     _capacity = tmp.capacity_;
//     arr = reinterpret_cast<T*>(new int8_t[_size * sizeof(T)]);
//     for (size_t i = 0; i < _size; i++)
//     {
//         new (arr + i) T(tmp[i]);
//     }
// }

// template<typename T>
// MyVec<T>::~MyVec() noexcept
// {
//     for (size_t i = 0; i < _size; i++)
//     {
//         (arr + i)->~T();
//     }

//     delete[] reinterpret_cast<int8_t*>(arr);
//     arr = nullptr;
//     _capacity = 0;
//     _size = 0;
// }

// template <typename T>
// size_t MyVec<T>::size() const
// {
//     return _size;
// }

// template <typename T>
// size_t MyVec<T>::capacity() const
// {
//     return _capacity;
// }

// template<typename T>
// size_t MyVec<T>::max_size() const
// {
//     return std::numeric_limits<std::size_t>::max() / sizeof(T);
// }

// template<typename T>
// void MyVec<T>::reserve(size_t n)
// {
//     if(n <= _capacity)
//     {return;}
//     T* newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
//     size_t i = 0;
//     try
//     {
//         for (; i < _size; ++i)
//         {
//             new (newarr + i) T(arr[i]);
//         }

//     }
//     catch (...)
//     {
//         for (size_t j = 0; j < i; ++j)
//         {
//             newarr[j]->~T();
//         }
//         delete[] reinterpret_cast<int8_t*>(newarr);
//         throw;
//     }

//     for (size_t i = 0; i < _size; ++i)
//     {
//         (arr+i)->~T();
//     }
//     delete[] reinterpret_cast<int8_t*>(arr);
//     arr = newarr;
//     _capacity = n;
// }

// template<typename T>
// void MyVec<T>::resize(size_t n, const T &value)
// {
//     if(n > _capacity)
//     {
//         reserve(n);
//     }
//     for (int i = _size; i < n; ++i)
//     {
//         new (arr + i) T(value);
//     }
//     if(n < _size)
//     {
//         _size = n;
//     }

// }

// template<typename T>
// void MyVec<T>::push_back(const T &value)
// {
//     if(_capacity == _size)
//     {
//         reserve(2 * _size);
//     }
//     new (arr + _size) T(value);
//     ++_size;
// }

// template<typename T>
// void MyVec<T>::pop_back()
// {
//     --_size;
//     (arr + _size)->~T();
// }

// template<typename T>
// void MyVec<T>::swap(MyVec<T> &vec)
// {
//     std::swap(vec._capacity,this->_capacity);
//     std::swap(vec._size,this->_size);
//     std::swap(vec,*this);
// }

// template<typename T>
// void MyVec<T>::clear()
// {
//     for (size_t i = 0; i < _size; ++i)
//     {
//         arr[i]->~T();
//     }
//     resize(0);
// }

// template<typename T>
// void MyVec<T>::insert(MyVec::c_iterator _pos, T const &tmp)
// {
//     size_t pos = (_pos).base() - arr;
//     reserve(_size + 1);
//     for (size_t i = _size; i > pos; i--)
//     {
//         new(arr + i) T(arr[i - 1]);
//         (arr + i - 1)->~T();
//     }
//     new(arr + pos) T(tmp);
//     _size++;
// }

// template<typename T>
// template<typename... Args>
// void MyVec<T>::emplace_back(Args &&... args)
// {
//     T tmp(args...);
//     push_back(tmp);
// }

// template<typename T>
// void MyVec<T>::assign(MyVec::c_iterator beg, MyVec::c_iterator end)
// {
//     clear();
//     int sz = end.base() - beg.base();
//     resize(sz);
//     for (auto i = 0; i < sz; i++)
//     {
//         new(arr + i) T(*(beg + i));
//     }
// }

// template<typename T>
// void MyVec<T>::erase(MyVec<T>::b_iterator beg, MyVec<T>::b_iterator end)
// {
//     int it_1 = beg.base() - arr;
//     int it_2 = end.base() - arr;
//     int len = it_2 - it_1;
//     for (auto i = it_1; i <= it_2; i++)
//     {
//         (arr + i)->~T();
//         new(arr + i) T(arr[i + 1]);
//     }
//     _size = _size - len;
// }

// template<typename T>
// template<typename... Args>
// void MyVec<T>::emplace(MyVec::c_iterator pos, Args &&... args)
// {
//     T tmp(args...);
//     insert(pos, tmp);
// }


// template<typename T>
// T& MyVec<T>::operator [](size_t i)
// {
//     return arr[i];
// }

// template<typename T>
// T& MyVec<T>::operator [](size_t i) const
// {
//     return arr[i];
// }

// template<typename T>
// T &MyVec<T>::at(size_t i)
// {

//     if(i >= _size)
//     {
//         throw std::out_of_range("MyVec -- out of range!");
//     }
//     return arr[i];
// }

// template<typename T>
// bool MyVec<T>::empty()
// {
//     return _size == 0;
// }

// template<typename T>
// T *MyVec<T>::data()
// {
//     return arr;
// }

// template<typename T>
// MyVec<T>::c_iterator MyVec<T>::cbegin() const
// {
//     return c_iterator(arr);
// }

// template<typename T>
// MyVec<T>::c_iterator MyVec<T>::cend() const
// {
//     return c_iterator(arr + _size);
// }

// template<typename T>
// MyVec<T>::b_iterator MyVec<T>::begin()
// {
//     return b_iterator(arr);
// }

// template<typename T>
// MyVec<T>::b_iterator MyVec<T>::end()
// {
//     return b_iterator(arr + _size);
// }

// template<typename T>
// MyVec<T>::r_iterator MyVec<T>::rbegin()
// {
//     return r_iterator(arr);
// }

// template<typename T>
// MyVec<T>::r_iterator MyVec<T>::rend()
// {
//     return r_iterator(arr + _size);
// }

// template<typename T>
// T &MyVec<T>::front()
// {
//     if(this->empty())
//     {
//         throw std::out_of_range("front() called on an empty vector");
//     }
//     return arr[0];
// }

// template<typename T>
// T &MyVec<T>::back()
// {
//     if(this->empty())
//     {
//         throw std::out_of_range("back() called on an empty vector");
//     }
//      return arr[_size];
// }
