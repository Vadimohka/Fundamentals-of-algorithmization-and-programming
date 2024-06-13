#ifndef BitSet_H
#define BitSet_H

#include <QList>
#include <algorithm>

class BitSet
{
private:
    int size = 0;
    int number = 0;

    QList <int> array;
public:
    BitSet(int ,int);

    int getSize();

    bool all();

    bool any();

    void flip(int);

    bool none();

    void set(int);

    bool test(int) ;

    QString to_string();

    unsigned long long to_ullong();

    unsigned long to_ulong();

    bool operator[](int pos);

};

#endif // BitSet_H
