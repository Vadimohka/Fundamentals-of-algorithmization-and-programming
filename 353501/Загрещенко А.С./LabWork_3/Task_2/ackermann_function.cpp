#include "ackermann_function.h"

Ackermann_function::Ackermann_function() {}

long long Ackermann_function::count(long m, long n)
{
    if (m == 0) {
        return n + 1;
    }
    
     else if (m > 0 && n == 0) {
        return (m - 1 , 1);
    } 
    
    else if (m > 0 && n > 0) {
        return count(m - 1, count(m, n - 1));
    }
}
