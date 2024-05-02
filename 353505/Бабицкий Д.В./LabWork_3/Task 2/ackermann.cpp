#include "ackermann.h"

Ackermann::Ackermann() {};

long long Ackermann::ack(long long m, long long n) {
    if (m==0) {
        return n+1;
    } else if (m>0 && n==0) {
        return ack(m-1,1);
    } else if (m>0 && n>0) {
        return ack(m-1, ack(m, n-1));
    }
}
