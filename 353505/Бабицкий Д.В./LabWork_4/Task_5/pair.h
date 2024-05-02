#ifndef PAIR_H
#define PAIR_H

#include <utility>

template<typename T1, typename T2>
struct Pair {
    T1 first;
    T2 second;

    Pair() = default;

    Pair(T1 a, T2 b);

    Pair(std::initializer_list<Pair> a);

    void operator=(Pair const &pair_);

};

#endif // PAIR_H
