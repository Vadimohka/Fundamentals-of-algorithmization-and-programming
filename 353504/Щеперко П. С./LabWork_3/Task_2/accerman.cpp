#include "accerman.h"

quint16 Accerman::AccermanFunc(const quint16 &m, const quint16 &n)
{
    if (m == 0){
        return n + 1;
    } else if (m > 0 && n == 0) {
        return AccermanFunc(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return AccermanFunc(m - 1, AccermanFunc(m, n - 1));
    }
}
