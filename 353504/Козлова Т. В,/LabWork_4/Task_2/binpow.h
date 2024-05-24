#ifndef BINPOW_H
#define BINPOW_H
#include <QtWidgets>
typedef long long ll;

class Binpow : public QObject
{
    Q_OBJECT
public:
    Binpow();

    static ll binpow(ll digit, ll power, ll mod);
};

#endif // BINPOW_H
