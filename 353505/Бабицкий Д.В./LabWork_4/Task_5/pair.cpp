#include "pair.h"

template<typename T1, typename T2>
Pair<T1, T2>::Pair(T1 a, T2 b) {
    this->first = a;
    this->second = b;
}

template<typename T1, typename T2>
Pair<T1, T2>::Pair(std::initializer_list<Pair> a) {
    pair(*a.begin());
}

template<typename T1, typename T2>
void Pair<T1, T2>::operator=(const Pair &pair_) {
    first = pair_.first;
    second = pair_.second;

}
