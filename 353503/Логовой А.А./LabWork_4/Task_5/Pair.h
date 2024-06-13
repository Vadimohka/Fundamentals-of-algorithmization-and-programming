#ifndef PAIR_H
#define PAIR_H

template<typename T1, typename T2>
class Pair{

public:

    T1 first;
    T2 second;

    Pair() : first(T1()), second(T2()) {}
    Pair(T1 fir, T2 sec) : first(fir), second(sec) {}

};

#endif // PAIR_H
