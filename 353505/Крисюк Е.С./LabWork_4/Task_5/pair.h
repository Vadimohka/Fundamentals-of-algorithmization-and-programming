#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>

class Pair
{
public:
    Pair(T1 a, T2 b) {
        this->first = a;
        this->second = b;
    }

    T1 first;
    T2 second;

};

#endif // PAIR_H
