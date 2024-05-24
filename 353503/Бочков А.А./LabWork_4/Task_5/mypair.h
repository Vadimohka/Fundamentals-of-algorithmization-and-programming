#ifndef MYPAIR_H
#define MYPAIR_H

template<typename Y, typename U>
class mypair
{
public:
    Y first;
    U second;

    // constructors

    mypair()
        : first(Y())
        , second(U())
    {}

    mypair(Y f, U s)
        : first(f)
        , second(s)
    {}

    mypair(const mypair &pair)
        : first(Y(pair.first))
        , second(U(pair.second))
    {}

    // assignment operators

    mypair &operator=(const mypair &pair)
    {
        first = Y(pair.first);
        second = U(pair.second);
        return *this;
    }

    // destuctor

    ~mypair() noexcept(noexcept(Y().~Y()) && noexcept(U().~U())) {}
};

#endif // MYPAIR_H
