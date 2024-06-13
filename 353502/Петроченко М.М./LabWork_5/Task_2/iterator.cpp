#include <climits>
#include <cstddef>
#include <type_traits>

template <bool is_const>
class CommonIterator {
   private:
    using Conditional_ref = std::conditional_t<is_const, const char&, char&>;
    using Conditional_ptr = std::conditional_t<is_const, const char*, char*>;
    std::conditional_t<is_const, const char*, char*> ptr_;

   public:
    explicit CommonIterator(char* ptr) { this->ptr_ = ptr; }

    CommonIterator(const CommonIterator<is_const>& other) {
        this->ptr_ = other.ptr_;
    }

    CommonIterator<is_const>& operator=(const CommonIterator<is_const>& other) {
        if (this == &other) {
            return *this;
        }
        this->ptr_ = other.ptr_;
        return *this;
    }

    CommonIterator<is_const>& operator+=(size_t n) {
        this->ptr_ += n;
        return *this;
    }

    friend CommonIterator<is_const> operator+(
        const CommonIterator<is_const>& lhs, size_t n) {
        auto copy = lhs;
        copy += n;
        return copy;
    }

    friend CommonIterator<is_const> operator+(
        size_t n, const CommonIterator<is_const>& rhs) {
        auto copy = *rhs;
        copy += n;
        return copy;
    }

    friend int operator-(const CommonIterator<is_const>& lhs,
                         const CommonIterator<is_const>& rhs) {
        return lhs.ptr_ - rhs.ptr_;
    }

    char& operator[](size_t i) { return *(this->ptr_ + i); }

    CommonIterator<is_const>& operator-=(size_t n) {
        this->ptr_ -= n;
        return *this;
    }

    CommonIterator<is_const> operator-(size_t n) {
        auto copy = *this;
        copy -= n;
        return copy;
    }

    CommonIterator<is_const>& operator++() {
        this->ptr_++;
        return *this;
    }

    CommonIterator<is_const>& operator++(int) {
        auto old = *this;
        this->operator++();
        return old;
    }

    CommonIterator<is_const>& operator--() {
        this->ptr_--;
        return *this;
    }

    CommonIterator<is_const>& operator--(int) {
        auto old = *this;
        this->operator--();
        return old;
    }

    bool operator<(const CommonIterator<is_const>& other) {
        return this->ptr_ < other.ptr_;
    }

    bool operator>(const CommonIterator<is_const>& other) {
        return other < *this;
    }

    bool operator<=(const CommonIterator<is_const>& other) {
        return !(*this > other);
    }

    bool operator>=(const CommonIterator<is_const>& other) {
        return !(*this < other);
    }

    bool operator==(const CommonIterator<is_const>& other) {
        return this->ptr_ == other.ptr_;
    }

    bool operator!=(const CommonIterator<is_const>& other) {
        return !(*this == other);
    }

    Conditional_ref operator*() { return *ptr_; }

    Conditional_ptr operator->() { return ptr_; }

    Conditional_ptr ptr() { return this->ptr_; }

    ~CommonIterator() = default;
};

class ReverseIterator {
   private:
    char* ptr_;

   public:
    explicit ReverseIterator(char* ptr) { this->ptr_ = ptr; }

    ReverseIterator(const ReverseIterator& other) { this->ptr_ = other.ptr_; }

    explicit ReverseIterator(CommonIterator<false> iter) {
        this->ptr_ = iter.ptr();
    }

    ReverseIterator& operator=(const ReverseIterator& other) {
        if (this == &other) {
            return *this;
        }
        this->ptr_ = other.ptr_;
        return *this;
    }

    ReverseIterator& operator+=(size_t n) {
        this->ptr_ -= n;
        return *this;
    }

    friend ReverseIterator operator+(const ReverseIterator& lhs, size_t n) {
        auto copy = lhs;
        copy -= n;
        return copy;
    }

    friend ReverseIterator operator+(size_t n, const ReverseIterator& rhs) {
        auto copy = rhs;
        copy -= n;
        return copy;
    }

    friend int operator-(const ReverseIterator& lhs,
                         const ReverseIterator& rhs) {
        return lhs.ptr_ - rhs.ptr_;
    }

    char& operator[](size_t i) { return *(this->ptr_ + i); }

    ReverseIterator& operator-=(size_t n) {
        this->ptr_ += n;
        return *this;
    }

    ReverseIterator operator-(size_t n) {
        auto copy = *this;
        copy += n;
        return copy;
    }

    ReverseIterator& operator++() {
        this->ptr_--;
        return *this;
    }

    ReverseIterator& operator++(int) {
        auto old = *this;
        this->operator++();
        return old;
    }

    ReverseIterator& operator--() {
        this->ptr_++;
        return *this;
    }

    ReverseIterator& operator--(int) {
        auto old = *this;
        this->operator--();
        return old;
    }

    bool operator<(const ReverseIterator& other) {
        return this->ptr_ > other.ptr_;
    }

    bool operator>(ReverseIterator& other) { return other < *this; }

    bool operator<=(ReverseIterator& other) { return !(*this > other); }

    bool operator>=(ReverseIterator& other) { return !(*this < other); }

    bool operator==(const ReverseIterator& other) {
        return this->ptr_ == other.ptr_;
    }

    bool operator!=(const ReverseIterator& other) { return !(*this == other); }

    char& operator*() { return *ptr_; }

    char* operator->() { return ptr_; }

    CommonIterator<false> base() { return CommonIterator<false>(this->ptr_); }

    char* ptr() { return this->ptr_; }

    ~ReverseIterator() = default;
};
