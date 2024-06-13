#ifndef MYPAIR_H
#define MYPAIR_H

#include <utility>
#include <algorithm>

//I am booored
template<typename first_type, typename second_type>
struct myPair
{
    first_type first;
    second_type second;

    myPair() = default;
    myPair(myPair& obj) : first(obj.first), second(obj.second)
    {

    }
    myPair(myPair&& obj) noexcept : first(std::move(obj.first)), second(std::move(obj.second))
    {

    }
    myPair(first_type& f, second_type& s) : first(f), second(s)
    {

    }

    template<typename U1 = first_type, typename U2 = second_type>
    myPair(U1&& f, U2&& s) : first(std::forward<U1>(f)), second(std::forward<U2>(s))
    {

    }

    template<typename U1, typename U2 >
    explicit myPair(myPair<U1, U2>& value) : first(value.first), second(value.second)
    {

    }

    template<typename U1, typename U2>
    explicit myPair(const myPair<U1, U2>& value) : first(value.first), second(value.second)
    {

    }



    myPair& operator=(const myPair& instance)
    {
        if (this == &instance)
        {
            return *this;
        }

        this->myPair(instance);
        return *this;
    }

    void swap()
    {
        swap(std::move(first), std::move(second));
    }

    bool operator==(const myPair& instance)
    {
        return instance.first == first && instance.second == second;
    }    
};

#endif // MYPAIR_H
