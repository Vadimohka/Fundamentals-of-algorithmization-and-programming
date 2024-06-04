#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;

    Pair(T1 _first, T2 _second)
        : first(_first)
        , second(_second)
    {}

    Pair() = default;

    bool operator==(const Pair<T1, T2> other)
    {
        return this->first == other.first && this->second == other.second;
    }
};

#endif // PAIR_H
