
//
// Created by g_alex on 3/31/23.
//


#ifndef L3T1_PAIR_H
#define L3T1_PAIR_H
#include <initializer_list>
template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    pair() = default;

    pair(T1 a, T2 b) {
        first = a;
        second = b;
    }

    pair(std::initializer_list<pair> a) {
        pair(*a.begin());
    }

    pair& operator=(pair const &pair_) {
        first = pair_.first;
        second = pair_.second;
        return *this;
    }

};
#endif //L3T1_PAIR_H
