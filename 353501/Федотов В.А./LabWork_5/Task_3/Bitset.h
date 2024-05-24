#pragma once

#include <QString>
#include <cstddef>
#include <cstdint>

class Bitset {
private:
    static const int SIZE = 16;

    uint16_t* m_data;
    size_t m_size;
public:
    explicit Bitset(size_t size);

    bool operator[](int index) const;
    bool &operator[](int index);

    bool all() const;
    bool any() const;
    bool none() const;

    int count() const;
    int size() const { return m_size; }
    void set(int index);
    void set();
    void reset(int index);
    void reset();
    bool test(int index) const;
    void flip(int index);
    void flip();

    QString to_string() const;
    unsigned long long to_ullong() const;
    unsigned long to_ulong() const;
};

