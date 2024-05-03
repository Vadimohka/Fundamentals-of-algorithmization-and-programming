#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
struct pair
{
    T1 firstType;
    T2 secondType;

    pair() = default;

    pair(T1 a, T2 b);

    void operator=(pair const &pair);
};

#endif // PAIR_H
