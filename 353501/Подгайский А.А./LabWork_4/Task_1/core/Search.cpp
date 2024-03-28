#include "Search.h"


long Search::binsearch(const QVector<long>& vect, long val) {
    return _binsearch(vect, val, 0, vect.size());
}

long Search::_binsearch(const QVector<long>& vect, long val, size_t beg, size_t end) {
    if(end - beg <= 1){
        return -1;
    }
    auto mid = (beg+end)/2;
    if(val > vect[mid]){
        return _binsearch(vect, val, mid, end);
    } else if(val < vect[mid]){
        return _binsearch(vect, val, beg, mid);
    } else{
        return mid;
    }
}
