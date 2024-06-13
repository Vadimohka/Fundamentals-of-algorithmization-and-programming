#include <climits>
#include <cstddef>
#include <type_traits>

template <bool is_const, typename T>
class CommonIterator {
   private:
    using Conditional_ref = std::conditional_t<is_const, const T&, T&>;
    using Conditional_ptr = std::conditional_t<is_const, const T*, T*>;
    std::conditional_t<is_const, const T*, T*> ptr_;

   public:
    explicit CommonIterator(T* ptr) { this->ptr_ = ptr; }

    CommonIterator(const CommonIterator<is_const, T>& other) {
        this->ptr_ = other.ptr_;
    }

    CommonIterator<is_const, T>& operator=(
        const CommonIterator<is_const, T>& other) {
        if (this == &other) {
            return *this;
        }
        this->ptr_ = other.ptr_;
        return *this;
    }

    CommonIterator<is_const, T>& operator+=(size_t n) {
        this->ptr_ += n;
        return *this;
    }

    friend CommonIterator<is_const, T> operator+(
        const CommonIterator<is_const, T>& lhs, size_t n) {
        auto copy = lhs;
        copy += n;
        return copy;
    }

    friend CommonIterator<is_const, T> operator+(
        size_t n, const CommonIterator<is_const, T>& rhs) {
        auto copy = *rhs;
        copy += n;
        return copy;
    }

    friend int operator-(const CommonIterator<is_const, T>& lhs,
                         const CommonIterator<is_const, T>& rhs) {
        return lhs.ptr_ - rhs.ptr_;
    }

    T& operator[](size_t i) { return *(this->ptr_ + i); }

    CommonIterator<is_const, T>& operator-=(size_t n) {
        this->ptr_ -= n;
        return *this;
    }

    CommonIterator<is_const, T> operator-(size_t n) {
        auto copy = *this;
        copy -= n;
        return copy;
    }

    CommonIterator<is_const, T>& operator++() {
        this->ptr_++;
        return *this;
    }

    CommonIterator<is_const, T>& operator++(int) {
        auto old = *this;
        this->operator++();
        return old;
    }

    CommonIterator<is_const, T>& operator--() {
        this->ptr_--;
        return *this;
    }

    CommonIterator<is_const, T>& operator--(int) {
        auto old = *this;
        this->operator--();
        return old;
    }

    bool operator<(const CommonIterator<is_const, T>& other) {
        return this->ptr_ < other.ptr_;
    }

    bool operator>(const CommonIterator<is_const, T>& other) {
        return other < *this;
    }

    bool operator<=(const CommonIterator<is_const, T>& other) {
        return !(*this > other);
    }

    bool operator>=(const CommonIterator<is_const, T>& other) {
        return !(*this < other);
    }

    bool operator==(const CommonIterator<is_const, T>& other) {
        return this->ptr_ == other.ptr_;
    }

    bool operator!=(const CommonIterator<is_const, T>& other) {
        return !(*this == other);
    }

    Conditional_ref operator*() { return *ptr_; }

    Conditional_ptr operator->() { return ptr_; }

    Conditional_ptr ptr() { return this->ptr_; }

    ~CommonIterator() = default;
};

template <typename T>
class ReverseIterator {
   private:
    T* ptr_;

   public:
    explicit ReverseIterator(T* ptr) { this->ptr_ = ptr; }

    ReverseIterator(const ReverseIterator<T>& other) {
        this->ptr_ = other.ptr_;
    }

    explicit ReverseIterator(CommonIterator<false, T> iter) {
        this->ptr_ = iter.ptr();
    }

    ReverseIterator<T>& operator=(const ReverseIterator<T>& other) {
        if (this == &other) {
            return *this;
        }
        this->ptr_ = other.ptr_;
        return *this;
    }

    ReverseIterator<T>& operator+=(size_t n) {
        this->ptr_ -= n;
        return *this;
    }

    friend ReverseIterator<T> operator+(const ReverseIterator<T>& lhs,
                                        size_t n) {
        auto copy = lhs;
        copy -= n;
        return copy;
    }

    friend ReverseIterator<T> operator+(size_t n,
                                        const ReverseIterator<T>& rhs) {
        auto copy = *rhs;
        copy -= n;
        return copy;
    }

    friend int operator-(const ReverseIterator<T>& lhs,
                         const ReverseIterator<T>& rhs) {
        return lhs.ptr_ - rhs.ptr_;
    }

    T& operator[](size_t i) { return *(this->ptr_ + i); }

    ReverseIterator<T>& operator-=(size_t n) {
        this->ptr_ += n;
        return *this;
    }

    ReverseIterator<T> operator-(size_t n) {
        auto copy = *this;
        copy += n;
        return copy;
    }

    ReverseIterator<T>& operator++() {
        this->ptr_--;
        return *this;
    }

    ReverseIterator<T>& operator++(int) {
        auto old = *this;
        this->operator++();
        return old;
    }

    ReverseIterator<T>& operator--() {
        this->ptr_++;
        return *this;
    }

    ReverseIterator<T>& operator--(int) {
        auto old = *this;
        this->operator--();
        return old;
    }

    bool operator<(const ReverseIterator<T>& other) {
        return this->ptr_ > other.ptr_;
    }

    bool operator>(const ReverseIterator<T>& other) { return other < *this; }

    bool operator<=(const ReverseIterator<T>& other) {
        return !(*this > other);
    }

    bool operator>=(const ReverseIterator<T>& other) {
        return !(*this < other);
    }

    bool operator==(const ReverseIterator<T>& other) {
        return this->ptr_ == other.ptr_;
    }

    bool operator!=(const ReverseIterator<T>& other) {
        return !(*this == other);
    }

    T& operator*() { return *ptr_; }

    T* operator->() { return ptr_; }

    CommonIterator<false, T> base() {
        return CommonIterator<false, T>(this->ptr_);
    }

    T* ptr() { return this->ptr_; }

    ~ReverseIterator() = default;
};
