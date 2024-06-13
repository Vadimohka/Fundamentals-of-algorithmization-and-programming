#ifndef MYPAIR_H
#define MYPAIR_H

#include <utility>
#include <algorithm>

template<typename first_type, typename second_type>
struct myPair
{
    first_type first;
    second_type second;

    /*************************ДЕФОЛТНЫЕ*КОНСТРУКТОРЫ*************************/

    myPair() = default;

    myPair(myPair& obj): first(obj.first), second(obj.second) {}

    myPair(myPair&& obj): first(std::move(obj.first)), second(std::move(obj.second)) {}

    myPair(first_type& f, second_type& s) : first(f), second(s) {}

    /*************************ЭФФЕКТНЫЕ*КОНСТРУКТОРЫ*************************/


    template<typename T, typename V >
    myPair(myPair<T, V>& value): first(value.first), second(value.second) {}

    template<typename T = first_type, typename V = second_type>
    myPair(T&& f, V&& s): first(std::forward<T>(f)), second(std::forward<V>(s)) {}

    template<typename T, typename V>
    myPair(const myPair<T, V>& value): first(value.first), second(value.second) {}



    void swap()
    {
        std::swap(std::move(first), std::move(second));
    }

    /************************ПЕРЕГРУЗКА*ОПЕРАТОРОВ***************************/

    bool operator==(const myPair& instance) // перегрузка оператора сравнения
    {
        return instance.first == first && instance.second == second;
    }

    myPair& operator=(const myPair& instance) // перегрузка оператора =
    {
        if (this == &instance)
        {
            return *this;
        }

        this->myPair(instance);
        return *this;
    }
};

#endif // MYPAIR_H
