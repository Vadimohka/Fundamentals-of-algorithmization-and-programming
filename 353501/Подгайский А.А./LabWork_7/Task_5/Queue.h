#ifndef A2CBDC6D_206C_4873_B159_BF8B88B55870
#define A2CBDC6D_206C_4873_B159_BF8B88B55870
#include "Deque.h"

template <typename T>
class Queue : private Deque<T> {
    
public:
    using Deque<T>::empty;
    using Deque<T>::size;
    using Deque<T>::Deque;
    using Deque<T>::operator[];
    void push(const T& t) { Deque<T>::push_back(t); }
    void pop() { Deque<T>::pop_front();}

    const T& front() const {return Deque<T>::front(); }
    const T& back() const {return Deque<T>::back(); }
    


};

#endif /* A2CBDC6D_206C_4873_B159_BF8B88B55870 */
