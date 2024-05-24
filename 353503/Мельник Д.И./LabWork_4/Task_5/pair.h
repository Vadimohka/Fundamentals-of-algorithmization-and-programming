#pragma once

#include <initializer_list>

template<typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;

    Pair() = default;

    Pair(T1 f, T2 s)
    {
        first = f;
        second = s;
    }

    Pair(std::initializer_list<Pair> list)
    {
        Pair(*list.begin());
    }

    void operator=(Pair const &pair)
    {
        first = pair.first;
        second = pair.second;
    }
};
