#include "string.h"
#include <sys/types.h>
#include <climits>
#include <cstdint>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <vector>

String::String() {
    this->m_size = 0;
    this->m_capacity = 0;
}

String::String(uint64_t len, char ch) {
    this->m_size = len;
    this->m_capacity = len;
    this->arr = std::make_unique<char[]>(len);
    for (uint64_t i = 0; i < len; ++i) {
        this->arr[i] = ch;
    }
}

String::String(const String& other) {
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->arr = std::make_unique<char[]>(this->m_capacity);
    for (uint64_t i = 0; i < this->m_size; ++i) {
        this->arr[i] = other.arr[i];
    }
}

String::String(const char* c_string) {
    this->m_size = strlen(c_string);
    this->m_capacity = this->m_size;
    this->arr = std::make_unique<char[]>(this->m_capacity);
    for (uint64_t i = 0; i < this->m_size; ++i) {
        this->arr[i] = c_string[i];
    }
}

String& String::operator=(const String& other) {
    this->m_size = other.m_size;
    if (this->m_capacity < this->m_size) {
        this->arr.reset();
        this->arr = std::make_unique<char[]>(this->m_size);
        this->m_capacity = this->m_size;
    }
    for (uint64_t i = 0; i < this->m_size; ++i) {
        this->arr[i] = other.arr[i];
    }
    return *this;
}

String& String::operator=(const char* c_string) {
    this->m_size = strlen(c_string);
    if (this->m_capacity < this->m_size) {
        this->arr.reset();
        this->arr = std::make_unique<char[]>(this->m_size);
        this->m_capacity = this->m_size;
    }
    for (uint64_t i = 0; i < this->m_size; ++i) {
        this->arr[i] = c_string[i];
    }
    return *this;
}

char& String::operator[](uint64_t i) {
    return this->arr[i];
}

char String::operator[](uint64_t i) const {
    return this->arr[i];
}

char String::at(uint64_t i) const {
    if (i >= 0 && i < this->m_size) {
        return this->arr[i];
    }
    throw new std::invalid_argument("index out of range");
}

char String::front() const {
    return this->at(0);
}

char String::back() const {
    return this->at(this->m_size - 1);
}

char* String::data() {
    return this->arr.get();
}

const char* String::c_str() const {
    if (this->back() != '\0') {
        auto other = String(*this);
        other.push_back('\0');
        return other.arr.get();
    }
    return this->arr.get();
}

String::ConstIterator String::cbegin() const {
    return ConstIterator(this->arr.get());
}

String::Iterator String::begin() {
    return Iterator(this->arr.get());
}

String::ConstIterator String::cend() const {
    return ConstIterator(this->arr.get() + this->size());
}

String::Iterator String::end() {
    return Iterator(this->arr.get() + this->size());
}

ReverseIterator String::rbegin() {
    return ReverseIterator(this->arr.get());
}

ReverseIterator String::rend() {
    return ReverseIterator(this->arr.get() + this->size());
}

bool String::empty() const {
    return (this->m_size == 0);
}

uint64_t String::length() const {
    return this->m_size;
}

uint64_t String::size() const {
    return this->m_size;
}

uint64_t String::max_size() const {
    return ULLONG_MAX;
}

void String::reserve(uint64_t new_cap) {
    auto new_arr = std::make_unique<char[]>(new_cap);
    for (int i = 0; i < this->size(); ++i) {
        new_arr[i] = this->arr[i];
    }
    this->arr.release();
    this->arr = std::move(new_arr);
    this->m_capacity = new_cap;
}

uint64_t String::capacity() const {
    return this->m_capacity;
}

void String::clear() {
    this->arr.release();
    this->m_size = 0;
    this->m_capacity = 0;
}

String& String::insert(uint64_t pos, uint64_t count, char ch) {
    if (pos + count >= this->m_capacity) {
        this->reserve(pos + count);
    }
    for (uint64_t i = 0; i < count; ++i) {
        this->arr[pos + i] = ch;
    }
    this->m_size = this->m_size + count;
    return *this;
}

String& String::insert(uint64_t pos, const char* cstr) {
    uint64_t cstr_len = strlen(cstr);
    if (pos + cstr_len >= this->m_capacity) {
        this->reserve(pos + cstr_len);
    }
    for (uint64_t i = 0; i < cstr_len; ++i) {
        this->arr[pos + i] = cstr[i];
    }
    this->m_size = this->m_size + cstr_len;
    return *this;
}

String& String::insert(uint64_t pos, const String& other) {
    if (pos + other.m_size >= this->m_capacity) {
        this->reserve(pos + other.m_size);
    }
    for (uint64_t i = 0; i < other.m_size; ++i) {
        this->arr[pos + i] = other[i];
    }
    this->m_size = this->m_size + other.m_size;
    return *this;
}

String& String::erase(uint64_t pos, uint64_t count) {
    if (pos + count > this->m_size) {
        count = this->m_size - pos;
    }
    if (pos + count == this->m_size) {
        this->m_size -= count;
        return *this;
    }
    for (uint64_t i = pos + count; i < this->m_size; ++i) {
        this->arr[i - count] = this->arr[i];
    }
    this->m_size -= count;
    return *this;
}

void String::push_back(char ch) {
    if (this->m_size == this->m_capacity) {
        this->reserve(this->m_capacity * 2);
    }
    this->m_size++;
    this->arr[this->m_size - 1] = ch;
}

void String::pop_back() {
    this->m_size--;
}

String& String::append(const char* cstr) {
    return this->insert(this->m_size, cstr);
}

String& String::append(const String& other) {
    return this->insert(this->m_size, other);
}

String& String::operator+=(const char* cstr) {
    return this->append(cstr);
}

String& String::operator+=(const String& other) {
    return this->append(other);
}

String& String::replace(uint64_t pos, const char* cstr) {
    uint64_t len = strlen(cstr);
    if (pos + len >= this->m_size) {
        len = this->m_size - pos;
    }
    for (uint64_t i = 0; i < len; ++i) {
        this->arr[pos + i] = cstr[i];
    }
    return *this;
}

String& String::replace(uint64_t pos, const String& other) {
    uint64_t len = other.length();
    if (pos + len >= this->m_size) {
        len = this->m_size - pos;
    }
    for (uint64_t i = 0; i < len; ++i) {
        this->arr[pos + i] = other[i];
    }
    return *this;
}

String& String::replace(uint64_t pos, uint64_t count, char ch) {
    if (pos + count >= this->m_size) {
        count = this->m_size - pos;
    }
    for (uint i = 0; i < count; ++i) {
        this->arr[i + pos] = ch;
    }
    return *this;
}

void String::resize(uint64_t new_size) {
    if (new_size < this->m_size) {
        this->m_size = new_size;
    } else if (this->m_size < new_size) {
        this->reserve(new_size);
        for (uint64_t i = this->size(); i < this->m_capacity; ++i) {
            this->arr[i] = '\0';
        }
        this->m_size = new_size;
    }
}

void String::swap(String& other) {
    std::swap(this->m_size, other.m_size);
    std::swap(this->m_capacity, other.m_capacity);
    std::swap(this->arr, other.arr);
}

uint64_t String::find(const char* cstr, uint64_t pos) const {
    auto pattern = String(cstr);
    auto res = kmp(*this, pattern);
    for (uint64_t found : res) {
        if (found >= pos) {
            return found;
        }
    }
    return ULLONG_MAX;
}

uint64_t String::find(const String& pattern, uint64_t pos) const {
    auto res = kmp(*this, pattern);
    for (uint64_t found : res) {
        if (found >= pos) {
            return found;
        }
    }
    return ULLONG_MAX;
}

uint64_t String::rfind(const char* cstr, uint64_t pos) const {
    auto pattern = String(cstr);
    auto res = kmp(*this, pattern);
    for (uint64_t i = res.size() - 1; i >= 0; --i) {
        if (res[i] >= pos) {
            return res[i];
        }
    }
    return ULLONG_MAX;
}

uint64_t String::rfind(const String& pattern, uint64_t pos) const {
    auto res = kmp(*this, pattern);
    for (uint64_t i = res.size() - 1; i >= 0; --i) {
        if (res[i] >= pos) {
            return res[i];
        }
    }
    return ULLONG_MAX;
}

int String::compare(const String& other) const {
    if (this->m_size < other.m_size) {
        return -1;
    } else if (this->m_size > other.m_size) {
        return 1;
    } else {
        for (uint64_t i = 0; i < this->m_size; ++i) {
            if (this->arr[i] > other.arr[i]) {
                return 1;
            } else if (this->arr[i] < other.arr[i]) {
                return -1;
            }
        }
        return 0;
    }
}

int String::compare(const char* cstr) const {
    auto other = String(cstr);
    return this->compare(other);
}

String String::substr(uint64_t pos, uint64_t count) {
    if (pos >= this->m_size) {
        throw std::out_of_range("pos out of range");
    }
    if (pos + count >= this->m_size) {
        count = m_size - pos;
    }
    String res = String(count, '\0');
    for (uint64_t i = 0; i < count; ++i) {
        res.arr[i] = this->arr[pos + i];
    }
    return res;
}

bool String::operator==(const String& other) const {
    return this->compare(other) == 0;
}

bool String::operator==(const char* other) const {
    return this->compare(other) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator!=(const char* other) const {
    return !(*this == other);
}

bool String::operator<(const String& other) const {
    return this->compare(other) < 0;
}

bool String::operator<(const char* other) const {
    return this->compare(other) < 0;
}

bool String::operator>(const String& other) const {
    return this->compare(other) > 0;
}

bool String::operator>(const char* other) const {
    return this->compare(other) > 0;
}

std::string String::print() const {
    std::string res;
    for (uint64_t i = 0; i < this->size(); ++i) {
        res.push_back(this->arr[i]);
    }
    return res;
}

String::~String() {
    this->arr.reset();
}

std::vector<uint64_t> String::kmp(const String& str, const String& pat) {
    uint64_t N = str.length();
    uint64_t M = pat.length();
    std::vector<uint64_t> res;
    auto lps_vec = lps(pat);
    uint64_t i = 0;
    uint64_t j = 0;
    while ((N - i) >= (M - j)) {
        if (pat[j] == str[i]) {
            j++;
            i++;
        }
        if (j == M) {
            res.push_back(i - j);
            j = lps_vec[j - 1];
        } else if (i < N && pat[j] != str[i]) {
            if (j != 0)
                j = lps_vec[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}

std::vector<uint64_t> String::lps(const String& str) {
    std::vector<uint64_t> res(str.length(), 0);
    uint64_t len = 0;
    uint64_t i = 1;
    res[0] = 0;
    while (i < str.length()) {
        if (str[i] == str[len]) {
            ++len;
            res[i] = len;
            ++i;
        } else {
            if (len != 0) {
                len = res[len - 1];
            } else {
                len = 0;
                ++i;
            }
        }
    }
    return res;
}
