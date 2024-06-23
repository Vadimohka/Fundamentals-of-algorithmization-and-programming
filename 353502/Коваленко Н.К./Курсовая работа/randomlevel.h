#ifndef RANDOMLEVEL_H
#define RANDOMLEVEL_H

#pragma once

#include <QFile>
#include <QTextStream>
#include <random>

namespace details
{
/// True if type T is applicable by a std::uniform_int_distribution
template<class T>
struct is_uniform_int {
    static constexpr bool value =
        std::is_same<T,              short>::value ||
        std::is_same<T,                int>::value ||
        std::is_same<T,               long>::value ||
        std::is_same<T,          long long>::value ||
        std::is_same<T,     unsigned short>::value ||
        std::is_same<T,       unsigned int>::value ||
        std::is_same<T,      unsigned long>::value ||
        std::is_same<T, unsigned long long>::value;
};

/// True if type T is applicable by a std::uniform_real_distribution
template<class T>
struct is_uniform_real {
    static constexpr bool value =
        std::is_same<T,       float>::value ||
        std::is_same<T,      double>::value ||
        std::is_same<T, long double>::value;
};
}

class Random
{
    template <class T> using IntDist = std::uniform_int_distribution<T>;
    template <class T> using RealDist = std::uniform_real_distribution<T>;

public:
    template <class T>
    static typename std::enable_if<details::is_uniform_int<T>::value, T>::type get(T from = std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max())
    {
        if (from > to) std::swap(from, to);
        IntDist<T> dist{from, to};
        return dist(instance().engine());
    }

    template <class T>
    static typename std::enable_if<details::is_uniform_real<T>::value, T>::type get(T from = std::numeric_limits<T>::min(), T to = std::numeric_limits<T>::max())
    {
        if (from > to) std::swap(from, to);
        RealDist<T> dist{from, to};
        return dist(instance().engine());
    }

    std::mt19937& engine() { return m_mt; }

protected:
    static Random& instance()
    {
        static Random inst;
        return inst;
    }

private:
    std::random_device m_rd; // Random Number Generator
    std::mt19937 m_mt;       // Standard random number generator

    Random() : m_mt(m_rd()) {}
    ~Random() {}
    Random(const Random&) = delete;
    Random& operator = (const Random&) = delete;

    void generateLevel();
};


#endif // RANDOMLEVEL_H
