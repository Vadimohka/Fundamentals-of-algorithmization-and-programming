#ifndef BITSET_H
#define BITSET_H

#include <string>

class bitset
{
    const short BLOCK=64;
    const unsigned long long MAX_VALUE=-1;
    unsigned long long *data_;
    int size_,capacity;
public:
    //Constructors
    bitset(int);
    ~bitset();

    //Operator
    bool operator[](int) const;
    bool &operator[](int);

    //Just methods
    bool all();
    bool any();
    int count();
    void flip();
    void flip(int);
    bool none();
    void reset();
    void reset(int);
    void set();
    void set(int);
    bool test(int);

    //To
    std::string to_string();
    unsigned long long to_ullong();

    //Getters
    unsigned long long *data();
    int size();

    void resize(int newSize);
};

#endif // BITSET_H
