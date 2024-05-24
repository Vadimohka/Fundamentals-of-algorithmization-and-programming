#ifndef MYPAIR_H
#define MYPAIR_H

#include <initializer_list>

template<typename T1, typename T2>
class MyPair {
public:
    MyPair() : first(), second() {}
    MyPair(const T1& first, const T2& second) : first(first), second(second) {}
    MyPair(std::initializer_list<MyPair> list) : MyPair(*list.begin()) {}

    MyPair& operator=(const MyPair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    T1 first;
    T2 second;
};

#endif // MYPAIR_H
