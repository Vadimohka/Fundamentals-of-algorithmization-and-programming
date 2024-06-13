#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H
#include<cstddef>

template<typename T>
class VectorIterator{

private:
    T* _data;

public:
    explicit VectorIterator(T* data) : _data(data) {}

    bool operator >= (const VectorIterator&ptr) const {
        return _data >= ptr._data;
    }

    bool operator <= (const VectorIterator&ptr) const {
        return _data <= ptr._data;
    }

    bool operator < (const VectorIterator&ptr) const {
        return _data < ptr._data;
    }

    bool operator > (const VectorIterator&ptr) const {
        return _data > ptr._data;
    }

    bool operator == (const VectorIterator&ptr) const {
        return _data == ptr._data;
    }

    bool operator!= (const VectorIterator&ptr) const {
        return _data != ptr._data;
    }

    T& operator *() const {
        return *_data;
    }

    VectorIterator& operator++ (){
        _data++;
        return *this;
    }

    VectorIterator& operator-- (){
        _data--;
        return *this;
    }

    VectorIterator& operator +=(size_t equanity){
        _data += equanity;
        return _data;
    }

    VectorIterator& operator -=(size_t equanity){
        _data -= equanity;
        return _data;
    }

    VectorIterator& operator - (const VectorIterator& ptr){
        return _data - ptr;
    }
};

#endif // VECTORITERATOR_H
