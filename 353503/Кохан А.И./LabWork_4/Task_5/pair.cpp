#include "pair.h"

template<typename T1, typename T2>
pair<T1, T2>::pair(T1 a, T2 b)
{
    this->firstType = a;
    this->secondType = b;
}

template<typename T1, typename T2>
void pair<T1, T2>::operator=(const pair &pair)
{
    firstType = pair.firstType;
    secondType = pair.secondType;
}
