#include "reversenumber.h"

ReverseNumber::ReverseNumber() {}

long long ReverseNumber::reverse(long long n)
{
    if(n == 0){
        return _answer;
    }
    else{
        _answer = _answer * 10 + _answer % 10;
        return reverse(_answer /= 10);
    }
}
