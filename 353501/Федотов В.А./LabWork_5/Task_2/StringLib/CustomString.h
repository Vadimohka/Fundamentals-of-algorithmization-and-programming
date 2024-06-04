#pragma once

#include <cstddef>
#include <memory>

class String {
private:
    std::unique_ptr<char[]> m_data;
    int m_size;

    void copyFrom(const char* source, size_t size);

public:
    class Iterator {
    private:
        char* m_ptr;

    public:
        Iterator(char* ptr) : m_ptr(ptr) {}

        Iterator& operator++() {
            ++m_ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++m_ptr;
            return temp;
        }

        Iterator& operator--() {
            --m_ptr;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --m_ptr;
            return temp;
        }

        char& operator*() const {
            return *m_ptr;
        }

        bool operator==(const Iterator& other) const {
            return m_ptr == other.m_ptr;
        }

        bool operator!=(const Iterator& other) const {
            return m_ptr != other.m_ptr;
        }
        
        // Random access operations
        Iterator& operator+=(int n) {
            m_ptr += n;
            return *this;
        }

        Iterator operator+(int n) const {
            return Iterator(m_ptr + n);
        }

        Iterator& operator-=(int n) {
            m_ptr -= n;
            return *this;
        }

        Iterator operator-(int n) const {
            return Iterator(m_ptr - n);
        }

        int operator-(const Iterator& other) const {
            return static_cast<int>(m_ptr - other.m_ptr);
        }

        char& operator[](int n) const {
            return m_ptr[n];
        }
    };

    String();
    String(const String &other);
    ~String() {};

    int compare(const String &other) const;
    size_t length() const;

    const char* getData() const { return m_data.get(); }

    String &operator=(const String &other);
    String &operator=(const char* str);
    String operator+(const String &other) const;
    bool operator<(const String &other) const { return compare(other) < 0; }
    bool operator>(const String &other) const { return compare(other) > 0; }
    bool operator==(const String &other) const { return compare(other) == 0; }
    bool operator!=(const String &other) const { return compare(other) != 0; }
    bool operator<=(const String &other) const { return compare(other) <= 0; }
    bool operator>=(const String &other) const { return compare(other) >= 0; }

    Iterator begin() { return Iterator(m_data.get()); }
    Iterator end() { return Iterator(m_data.get() + m_size); }
    const Iterator cbegin() const { return Iterator(m_data.get()); }
    const Iterator cend() const { return Iterator(m_data.get() + m_size); }


};