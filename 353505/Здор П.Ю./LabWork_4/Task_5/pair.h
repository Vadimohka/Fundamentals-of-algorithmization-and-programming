#ifndef PAIR_H
#define PAIR_H
#include <initializer_list>
#include "vect.h"
template <typename T1,typename T2>
class pair
{
private:
    T1 a;
    T2 b;
public:
    pair(T1 a,T2 b){
        this->a=a;
        this->b=b;
    }
    pair(std::initializer_list<pair> a) {
        pair(*a.begin());
    }
};

#endif // PAIR_H
