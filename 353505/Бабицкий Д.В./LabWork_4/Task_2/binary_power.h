#ifndef BINARY_POWER_H
#define BINARY_POWER_H

#include <QVector>

class binary_power
{
public:
    binary_power();
    long long get_result(long long digit, long long powder, long long mod);
private:
    long long binpow(long long digit, long long powder, long long mod);
};

#endif // BINARY_POWER_H
