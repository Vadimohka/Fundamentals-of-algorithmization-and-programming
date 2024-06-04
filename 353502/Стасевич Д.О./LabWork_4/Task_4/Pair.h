#ifndef TASK4_PAIR_H
#define TASK4_PAIR_H

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair() = default;
    Pair(T1 f, T2 s)
    {
        first = f;
        second = s;
    }
    static Pair make_pair(T1 f, T2 s)
    {
        return Pair(f, s);
    }

};


#endif //TASK4_PAIR_H
