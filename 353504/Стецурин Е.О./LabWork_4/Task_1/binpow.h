#ifndef BINPOW_H
#define BINPOW_H

#include <QtWidgets>

class Binpow : public QObject
{
    Q_OBJECT
public:
    Binpow();

    static long long binpow(long long digit, long long powder, long long mod);
};

#endif // BINPOW_H
