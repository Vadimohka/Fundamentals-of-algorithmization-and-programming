#include "mystdstring.h"

MyStdString::MyStdString() : data_(std::make_unique<char[]>(size_update)), reserved_(size_update), size_(0) {
    data_[0] = '\0';
}

MyStdString::MyStdString(const char* str) : data_(nullptr), reserved_(0), size_(0) {
    const char* c = str;
    while (*c != '\0') {
        my_push_back(*c);
        ++c;
    }
}

MyStdString::MyStdString(const MyStdString& other) : size_(other.size_) {
    data_ = std::make_unique<char[]>(size_ + 1);
    std::memcpy(data_.get(), other.data_.get(), size_ + 1);
    reserved_ = size_ + 1;
}

MyStdString::MyStdString(size_t reserve) : data_(std::make_unique<char[]>(reserve + 1)), reserved_(reserve + 1), size_(0) {
    data_[0] = '\0';
}

MyStdString::~MyStdString() = default;

// Методы доступа к размерам
int MyStdString::my_size() const {
    return size_;
}

int MyStdString::my_capacity() const {
    return reserved_;
}

bool MyStdString::my_empty() const {
    return size_ == 0;
}

size_t MyStdString::my_max_size() const {
    return std::numeric_limits<size_t>::max();
}

// Методы доступа к символам
char MyStdString::my_front() const noexcept {
    if (size_ == 0) {
        return '\0';
    }
    return data_[0];
}

char MyStdString::my_back() const noexcept {
    if (size_ == 0) {
        return '\0';
    }
    return data_[size_ - 1];
}

const char* MyStdString::my_c_str() const noexcept {
    return data_.get();
}

// Методы изменения размера и емкости
void MyStdString::my_resize(size_t sz, char def) {
    if (sz >= size_) {
        my_reserve(sz);
        char* ptr = data_.get();
        for (size_t i = size_; i < sz; ++i) {
            ptr[i] = def;
        }
        ptr[sz] = '\0';
    } else {
        char* n_data = new char[sz + 1];
        std::memcpy(n_data, data_.get(), sz);
        n_data[sz] = '\0';
        data_.reset(n_data);
        reserved_ = sz + 1;
        size_ = sz;
    }
}

void MyStdString::my_reserve(size_t sz) {
    if (reserved_ >= sz) {
        return;
    } else {
        std::unique_ptr<char[]> new_data(new char[sz]);
        std::memcpy(new_data.get(), data_.get(), size_ + 1);
        data_.reset(new_data.release());
        reserved_ = sz;
    }
}

// Методы добавления и удаления символов
void MyStdString::my_push_back(char c) {
    if (size_ + 1 >= reserved_) {
        my_reserve(size_ + 1);
    }
    data_[size_++] = c;
    data_[size_] = '\0';
}

void MyStdString::my_pop_back() {
    if (size_ > 0) {
        --size_;
        data_[size_] = '\0';
    }
}

// Методы добавления и вставки других строк
void MyStdString::my_append(const MyStdString& other) {
    size_t old_sz = size_;
    my_resize(size_ + other.size_, '\0');
    std::memcpy(data_.get() + old_sz, other.data_.get(), other.size_);
}

void MyStdString::my_append(char c) {
    my_push_back(c);
}

void MyStdString::my_insert(size_t pos, const char* str) {
    if (pos > size_) {
        throw std::out_of_range("Position out of range");
    }
    size_t len = std::strlen(str);
    my_resize(size_ + len, '\0');
    std::memmove(data_.get() + pos + len, data_.get() + pos, size_ - pos);
    std::memcpy(data_.get() + pos, str, len);
}

void MyStdString::my_insert(size_t pos, const MyStdString& str) {
    my_insert(pos, str.data_.get());
}

void MyStdString::my_insert(size_t pos, size_t n, char c) {
    if (pos > size_) {
        throw std::out_of_range("Position out of range");
    }
    my_resize(size_ + n, '\0');
    std::memmove(data_.get() + pos + n, data_.get() + pos, size_ - pos);
    std::memset(data_.get() + pos, c, n);
}

// Методы удаления части строки
void MyStdString::my_clear() {
    data_.reset(new char[size_update]);
    reserved_ = size_update;
    size_ = 0;
    data_[0] = '\0';
}

void MyStdString::my_erase(int x) {
    if (x < 0 || x >= static_cast<int>(size_)) {
        throw std::out_of_range("Index out of range");
    }
    std::memmove(data_.get() + x, data_.get() + x + 1, size_ - x);
    --size_;
}

MyStdString::my_iterator MyStdString::my_begin() {
    return data_.get();
}

MyStdString::my_iterator MyStdString::my_end() {
    return data_.get() + size_;
}

MyStdString::my_const_iterator MyStdString::my_cbegin() const {
    return data_.get();
}

MyStdString::my_const_iterator MyStdString::my_cend() const {
    return data_.get() + size_;
}


char& MyStdString::operator[](size_t x){
    if (x >= size_) {
        throw std::out_of_range("");
    }
    return data_[x];
}

char MyStdString::operator[](size_t x) const {
    if (x >= size_) {
        throw std::out_of_range("");
    }
    return data_[x];
}

char& MyStdString::my_at(size_t x) {
    if (x >= size_) {
        throw std::out_of_range("");
    }
    return data_[x];
}

char MyStdString::my_at(size_t x) const {
    if (x >= size_) {
        throw std::out_of_range("");
    }
    return data_[x];
}
