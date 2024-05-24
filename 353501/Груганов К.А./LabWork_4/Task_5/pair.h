#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;

    //по умол
    Pair()
        : first(T1())
        , second(T2()){};

    //инициализирующий
    Pair(const T1 &first, const T2 &second)
        : first(first)
        , second(second)
    {}

    bool operator!=(const Pair &other) const { !(*this == other); }

    Pair &operator=(const Pair &other)
    {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    const T1 &getFirst() const { return first; }

    const T2 &getSecond() const { return second; }
};

#endif // PAIR_H
