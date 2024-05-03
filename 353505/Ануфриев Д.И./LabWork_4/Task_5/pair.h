#ifndef PAIR_H
#define PAIR_H

#include <initializer_list>

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair() = default;

    pair(T1 a, T2 b) {
        this->first = a;
        this->second = b;
    }

    pair(std::initializer_list<pair> a) {
        pair(*a.begin());
    }

    void operator=(pair const &pair_) {
        first = pair_.first;
        second = pair_.second;

    }

};
#endif //L3T1_PAIR_H
