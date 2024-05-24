#ifndef BITSET_H
#define BITSET_H
#include <QVector>
#include <algorithm>
class bitset
{
private:
    int size=0;
    int a=0;

    QVector <int> initial;
public:
    explicit bitset(int ,int);

    ~bitset();

    int getSize();

    bool all();

    bool any();

    void flip(int k);

    bool none();

    void set(int k);

    bool test(int k)const;

    QString to_string();

    unsigned long long to_ullong();

    unsigned long to_ulong();

    bool operator[](int pos)const;
    bool& operator[](int pos);
};

#endif // BITSET_H
