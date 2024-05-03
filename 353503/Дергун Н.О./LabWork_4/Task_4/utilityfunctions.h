#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H

#include <QDebug>

namespace My {

    template<typename T>
    std::remove_reference_t<T>&& move(T&& a) {
        return static_cast<std::remove_reference_t<T>&&>(a);
    }

    template<typename T>
    T&& forward(std::remove_reference_t<T>& a) {
        return static_cast<T&&>(a);
    }

    template<typename T>
    void swap(T& a, T& b) {
        T t = a;
        a = b;
        b = move(t);
    }


    // pair implementation

    template<typename Y, typename U>
    class Pair {
    public:
        Y first;
        U second;


        // constructors

        Pair() : first (Y()), second (U()) {}

        template<typename YY, typename UU>
        Pair(YY&& first, UU&& second) : first (forward<YY>(first)), second (forward<UU>(second)) {}

        Pair(const Pair& pair) : first(Y(pair.first)), second(U(pair.second)) {}

        Pair(Pair&& pair) :
            first(Y(move(pair).first)),
            second(U(move(pair).second)) {
            pair.first = Y();
            pair.second = U();
        }


        // assignment operators

        Pair& operator= (const Pair& pair) {
            first = Y(pair.first);
            second = U(pair.second);
            return *this;
        }
        Pair& operator= (Pair&& pair) {
            first = Y(move(pair).first);
            second = U(move(pair).second);
            pair.first = move(Y());
            pair.second = move(U());
            return *this;
        }


        // destuctor

        ~Pair() noexcept(noexcept(Y().~Y()) && noexcept(U().~U())) {}
    };
}  // namespace My

#endif // UTILITYFUNCTIONS_H
