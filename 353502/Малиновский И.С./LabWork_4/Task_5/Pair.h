#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair() : first(T1()), second(T2()) {}
    Pair(const T1& a, const T2& b) : first(a), second(b) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    bool operator==(const Pair& other) const {
        return (first == other.first && second == other.second);
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }
};

#endif // PAIR_H
