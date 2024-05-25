#ifndef MODEL_SHAREDPTR_H_
#define MODEL_SHAREDPTR_H_

#include "app/shortcuts.h"

namespace model {

template <class T>
class SharedPtr;  // Dichiarazione incompleta

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right);  // Dichiarazione incompleta

template <class T, class... Args>
SharedPtr<T> make_shared(Args&&... args);

template <class T>
class SharedPtr {
    friend bool operator==<T>(const SharedPtr& left, const SharedPtr& right);
    friend bool operator!=<T>(const SharedPtr& left, const SharedPtr& right);

   private:
    T* _ptr;
    U_LINT* _counter;

   public:
    SharedPtr(T* ptr = nullptr);
    SharedPtr(const SharedPtr<T>& SharedPtr);

    SharedPtr<T>& operator=(const SharedPtr<T>& SharedPtr);
    void swap(SharedPtr<T>& SharedPtr);

    operator bool() const;

    T* get();
    T& operator*();
    T* operator->();
    T& operator[](U_LINT index);

    const T* get() const;
    const T& operator*() const;
    const T* operator->() const;
    const T& operator[](U_LINT index) const;

    void reset(T* ptr = nullptr);

    U_LINT use_count() const;

    ~SharedPtr();
};

template <class T>
bool operator==(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr == right._ptr;
}

template <class T>
bool operator!=(const SharedPtr<T>& left, const SharedPtr<T>& right) {
    return left._ptr != right._ptr;
}

template <class T>
SharedPtr<T>::SharedPtr(T* ptr) : _ptr(ptr), _counter(ptr ? new U_LINT(1) : new U_LINT(0)) {}

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& SharedPtr) : _ptr(SharedPtr._ptr), _counter(SharedPtr._counter) {
    if (_ptr != nullptr) {
        (*_counter)++;
    } else {
        _counter = new U_LINT(0);
    }
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& SharedPtr) {
    if (this != &SharedPtr) {
        if (*_counter > 0) {
            (*_counter)--;
        }

        if (*_counter <= 0) {
            delete _ptr;
            delete _counter;
            _ptr = nullptr;
            _counter = nullptr;
        }

        _ptr = SharedPtr._ptr;
        _counter = SharedPtr._counter;

        if (_ptr != nullptr) {
            (*_counter)++;
        } else {
            _counter = new U_LINT(0);
        }
    }
    return *this;
}

template <class T>
void SharedPtr<T>::swap(SharedPtr<T>& SharedPtr) {
    T* temp = _ptr;
    U_LINT* tempCount = _counter;

    _ptr = SharedPtr._ptr;
    SharedPtr._ptr = temp;

    _counter = SharedPtr._counter;
    SharedPtr._counter = tempCount;
}

template <class T>
SharedPtr<T>::operator bool() const {
    return _ptr != nullptr;
}

template <class T>
T* SharedPtr<T>::get() {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator*() {
    return *_ptr;
}

template <class T>
T* SharedPtr<T>::operator->() {
    return _ptr;
}

template <class T>
T& SharedPtr<T>::operator[](U_LINT index) {
    return _ptr[index];
}

template <class T>
const T* SharedPtr<T>::get() const {
    return _ptr;
}

template <class T>
const T& SharedPtr<T>::operator*() const {
    return *_ptr;
}

template <class T>
const T* SharedPtr<T>::operator->() const {
    return _ptr;
}

template <class T>
const T& SharedPtr<T>::operator[](U_LINT index) const {
    return _ptr[index];
}

template <class T>
void SharedPtr<T>::reset(T* ptr) {
    if (*_counter > 0) {
        (*_counter)--;
    }
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
        _ptr = nullptr;
        _counter = nullptr;
    }
    _ptr = ptr;
    _counter = ptr ? new U_LINT(1) : new U_LINT(0);
}

template <class T>
U_LINT SharedPtr<T>::use_count() const {
    return (_counter ? *_counter : 0);
}

template <class T>
SharedPtr<T>::~SharedPtr() {
    if (*_counter > 0) {
        (*_counter)--;
    }
    if (*_counter <= 0) {
        delete _ptr;
        delete _counter;
        _ptr = nullptr;
        _counter = nullptr;
    }
}

template <class T, class... Args>
SharedPtr<T> make_shared(Args&&... args) {
    return SharedPtr<T>(new T(args...));
}

}  // namespace model

#endif
