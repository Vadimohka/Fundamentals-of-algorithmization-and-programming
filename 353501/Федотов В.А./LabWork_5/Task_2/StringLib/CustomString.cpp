#include "CustomString.h"
#include "CString.h"
#include <cstddef>

String::String() {
    m_data = std::make_unique<char[]>(1);
    m_data[0] = 0;
    m_size = 0;
}

String::String(const String &other){ copyFrom(other.m_data.get(), other.m_size); }

void String::copyFrom(const char* source, size_t size) {
    m_data = std::make_unique<char[]>(size + 1);
    for (size_t i = 0; i < size; i++) {
        m_data[i] = source[i];
    }
    m_size = size;
    m_data[size] = 0;
}

int String::compare(const String &other) const {
    if (this->m_size != other.m_size)
        return this->m_size - other.m_size;

    for (size_t i = 0; i < m_size; i++) {
        if (this->m_data[i] != other.m_data[i]) {
            return (this->m_data[i] > other.m_data[i]) ? 1 : -1;
        }
    }

    return 0;
}

size_t String::length() const {
    for (size_t i = 0; i < m_size; i++) {
        if (m_data[i] == 0) 
            return i;
    }

    return m_size;
}

String &String::operator=(const String &other) { 
    copyFrom(other.m_data.get(), other.m_size);
    
    return *this;
}

String &String::operator=(const char* str) {
    copyFrom(str, cstring::strlen(str));
    return *this;
}

String String::operator+(const String &other) const {
    String res;
    res.m_size = this->m_size + other.m_size;
    res.m_data = std::make_unique<char[]>(res.m_size + 1);

    size_t pos = 0;
    for (size_t i = 0; i < this->m_size; ++i) {
        if (this->m_data[i] == 0) 
            break;
        res.m_data[pos++] = this->m_data[i];
    }

    for (size_t i = 0; i < other.m_size; ++i) {
        if (other.m_data[i] == 0)
            break;
        res.m_data[pos++] = other.m_data[i];
    }

    res.m_data[pos] = 0;
    res.m_size = pos;
    return res;
}