#ifndef NODEDEQUE_H
#define NODEDEQUE_H


template<class T>
class NodeDeque {
public:
    NodeDeque(){}
    ~NodeDeque(){}
    int count = 0;
    NodeDeque<T> *prev = nullptr;
    NodeDeque<T> *next = nullptr;
    T *data = new T[4];
};

#endif // NODEDEQUE_H
