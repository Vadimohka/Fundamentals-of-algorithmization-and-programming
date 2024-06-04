#ifndef MYBITSET_H
#define MYBITSET_H

#include <QVector>

class MyBitset
{
private:
    QVector<int> _bits;
    size_t _size{1};
    size_t _capacity{32};

public:
    MyBitset();
    explicit MyBitset(int size);
    MyBitset(MyBitset const &other);

    void set(size_t pos);
    bool get(size_t pos);
    bool operator[](size_t pos) const;

    void resize(size_t newSize);
    bool all();
    bool any();
    size_t count();
    void flip();
    bool none();
    void reset();
    void reset(size_t pos);
    void set();
    size_t size();
    bool test(size_t pos);
    QString to_string();
    unsigned long long to_ullong();
    unsigned long to_ulong();
};

#endif // MYBITSET_H
