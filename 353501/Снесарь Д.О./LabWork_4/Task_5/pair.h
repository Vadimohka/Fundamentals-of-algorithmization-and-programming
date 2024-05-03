#ifndef PAIR_H
#define PAIR_H


#include <initializer_list>

template<typename T1, typename T2>
struct Pair {
public:
    T1 first;
    T2 second;
    Pair() = default;
    Pair(T1 first, T2 second) {
        this->first = first;
        this->second = second;
    }
    Pair(std::initializer_list<Pair> a) {
        Pair(*a.begin());
    }
    void operator=(Pair const &pair_) {
        first = pair_.first;
        second = pair_.second;
    }


};


#endif // PAIR_H
