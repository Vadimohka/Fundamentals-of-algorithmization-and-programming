#include "vector.h"

template <typename T>

Vector<T>::Vector() {

    vector_size = 0;
    vector_capacity = 0;
    array = nullptr;
}


template <typename T>
Vector<T>::Vector(size_t length) {

    reserve(length);
    resize(length);

    for(size_t i = 0; i < length; ++i){
        array[i] = T();
    }
}

template <typename T>
Vector<T>::~Vector(){
    clear();
}

template <typename T>

T &Vector<T>::operator[](size_t number) {
    return array[number];
}

template <typename T>
void Vector<T>::assign(size_t count, T number){
    clear();
    resize(count);

    for(size_t i = 0; i < vector_size; ++i){
        array[i] = number;
    }

}
template <typename T>
T& Vector<T>::at(size_t pos){
    return array[pos];
}

template <typename T>
size_t Vector<T>::capacity(){
    return vector_capacity;
}

template <typename T>
bool Vector<T>::empty(){
    return vector_size == 0;
}

template <typename T>
T& Vector<T>::front(){
    return array[0];
}

template <typename T>
T& Vector<T>::back(){
    return array[vector_size - 1];
}

template <typename T>
size_t Vector<T>::max_size(){
    return vector_capacity / sizeof(T);
}

template <typename T>
void Vector<T>::pop_back(T){
    vector_size--;
    (array + vector_size) -> ~T();
}

template <typename T>
void Vector<T>::push_back(T number){

    vector_size++;
    resize(vector_size);

    array[vector_size - 1] = number;

}

template <typename T>
size_t Vector<T>::size(){
    return vector_size;
}


template <typename T>
void Vector<T>::reserve(size_t length){

    if(length > vector_capacity){
        T* new_array = new T[2 * length];

        for(size_t i = 0; i < vector_size; ++i){
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        vector_capacity = length;
    }

}

template <typename T>
void Vector<T>::swap(Vector<T> &second_vector){

    size_t temp_size = vector_size;
    size_t temp_capacity = vector_capacity;

    T* temp_array = new T[temp_size];

    for(size_t i = 0; i < temp_size; ++i){
        temp_array[i] = array[i];
    }

    resize(second_vector.size());

    for(size_t i = 0; i < second_vector.size(); ++i){
        array[i] = second_vector[i];
    }

    reserve(temp_capacity);

    second_vector.resize(temp_size);

    for(size_t i = 0; i < temp_size; ++i){
        second_vector[i] = temp_array[i];
    }

    second_vector.reserve(temp_capacity);
}

template <typename T>
void Vector<T>::resize(size_t length){

    if(length > vector_capacity){
        reserve(length);
    }


    if(length > vector_size){

        for(size_t i = vector_size; i < length; ++i){

            array[i] = T();
        }

    }
    else{

        for (size_t i = length; i < vector_size; ++i) {
            (array + i) -> ~T();
        }

    }

    vector_size = length;
}

template <typename T>
void Vector<T>::clear(){

    for (size_t i = 0; i < vector_size; i++) {
        (array + i) -> ~T();
    }

    delete[] array;

    array = nullptr;
    vector_capacity = 0;
    vector_size = 0;
}
template <typename T>

T& Vector<T>::data(){

    return array[0];
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(Vector::citerator pos, Args ... args) {
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(array);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(array + vector_size);
}

template <typename T>
typename Vector<T>::citerator Vector<T>::cbegin(){
    return citerator(array);
}

template <typename T>
typename Vector<T>::riterator Vector<T>::rbegin(){
    return riterator(array + vector_size);
}

template <typename T>
typename Vector<T>::riterator Vector<T>::rend(){
    return riterator(array);
}

template class Vector<int>;
