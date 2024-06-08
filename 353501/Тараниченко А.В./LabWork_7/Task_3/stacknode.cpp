#include "stacknode.h"

template <typename T>
StackNode<T>::StackNode() : data(T()), next(nullptr) {}

template <typename T>
StackNode<T>::StackNode(T value) : data(value), next(nullptr) {}

template <typename T>
StackNode<T>::StackNode(const StackNode& n) : data(n.data), next(n.next) {}

template <typename T>
StackNode<T>::~StackNode() {
}
