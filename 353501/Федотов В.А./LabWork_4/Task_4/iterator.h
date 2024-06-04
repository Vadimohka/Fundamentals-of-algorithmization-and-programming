#include <cstddef>

template<typename T>
class Iterator {

private:
    T *m_Ptr;

public:
    Iterator(T *ptr)
        : m_Ptr(ptr) {}

    ~Iterator() = default;

    const T *base() const {
        return m_Ptr;
    }

    Iterator operator+(int n){
        return Iterator(m_Ptr + n);
    } 

    Iterator operator-(int n){
        return Iterator(m_Ptr - n);
    } 

    int operator-(Iterator other){
        return m_Ptr - other.m_Ptr;
    }

    Iterator& operator++(){
        m_Ptr++;
        return *this;
    }

    Iterator operator++(int){
        Iterator iterator = *this;
        ++(*this);
        return iterator;
    }

    Iterator& operator--(){
        m_Ptr--;
        return *this;
    }

    Iterator operator--(int){
        Iterator iterator = *this;
        --(*this);
        return iterator;
    }

    T& operator[](int index){
        return *(m_Ptr + index);
    }

    T* operator->(){
        return m_Ptr;
    }

    T& operator*(){
        return *m_Ptr;
    }

    bool operator==(const Iterator& other) const {
        return m_Ptr == other.m_Ptr;
    }
    
    bool operator!=(const Iterator& other) const {
        return !(*this == other);
    }

    bool operator<(const Iterator& other) const {
        return m_Ptr < other.m_Ptr;
    }

    bool operator>(const Iterator& other) const {
        return m_Ptr > other.m_Ptr;
    }

    bool operator<=(const Iterator& other) const {
        return m_Ptr <= other.m_Ptr;
    }

    bool operator>=(const Iterator& other) const {
        return m_Ptr >= other.m_Ptr;
    }
};

template<typename T>
class Reverse_Iterator {

private:
    T* m_Ptr;

public:
    Reverse_Iterator(T* ptr)
        : m_Ptr(ptr) {}

    ~Reverse_Iterator() = default;

    Reverse_Iterator operator+(int n) {
        return Reverse_Iterator(m_Ptr - n);
    }

    Reverse_Iterator operator-(int n) {
        return Reverse_Iterator(m_Ptr + n);
    }

    int operator-(Reverse_Iterator other) {
        return other.m_Ptr - m_Ptr;
    }

    Reverse_Iterator& operator++() {
        m_Ptr--;
        return *this;
    }

    Reverse_Iterator operator++(int) {
        Reverse_Iterator iterator = *this;
        ++(*this);
        return iterator;
    }

    Reverse_Iterator& operator--() {
        m_Ptr++;
        return *this;
    }

    Reverse_Iterator operator--(int) {
        Reverse_Iterator iterator = *this;
        --(*this);
        return iterator;
    }

    T& operator[](int index) {
        return *(m_Ptr - index);
    }

    T* operator->() {
        return m_Ptr;
    }

    T& operator*() {
        return *m_Ptr;
    }

    bool operator==(const Reverse_Iterator& other) const {
        return m_Ptr == other.m_Ptr;
    }

    bool operator!=(const Reverse_Iterator& other) const {
        return !(*this == other);
    }

    bool operator<(const Reverse_Iterator& other) const {
        return m_Ptr > other.m_Ptr;
    }

    bool operator>(const Reverse_Iterator& other) const {
        return m_Ptr < other.m_Ptr;
    }

    bool operator<=(const Reverse_Iterator& other) const {
        return m_Ptr >= other.m_Ptr;
    }

    bool operator>=(const Reverse_Iterator& other) const {
        return m_Ptr <= other.m_Ptr;
    }
};