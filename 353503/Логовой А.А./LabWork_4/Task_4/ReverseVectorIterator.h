#ifndef REVERSEVECTORITERATOR_H
#define REVERSEVECTORITERATOR_H
#include<cstddef>

template<typename T>
class ReverseVectorIterator{

private:
    T* _data;

public:
    explicit ReverseVectorIterator(T* data) : _data(data) {}

    bool operator >= (const ReverseVectorIterator&ptr) const {
        return _data >= ptr._data;
    }

    bool operator <= (const ReverseVectorIterator&ptr) const {
        return _data <= ptr._data;
    }

    bool operator < (const ReverseVectorIterator&ptr) const {
        return _data < ptr._data;
    }

    bool operator > (const ReverseVectorIterator&ptr) const {
        return _data > ptr._data;
    }

    bool operator == (const ReverseVectorIterator&ptr) const {
       return _data == ptr._data;
    }

    bool operator != (const ReverseVectorIterator&ptr) const {
       return _data != ptr._data;
    }

    T& operator *() const {
        return *_data;
    }

    ReverseVectorIterator&  operator++ (){
        _data--;
        return *this;
    }

    ReverseVectorIterator& operator-- (){
        _data++;
        return *this;
    }

    ReverseVectorIterator& operator +=(size_t equanity){
        _data -= equanity;
        return *this;
    }

    ReverseVectorIterator& operator -=(size_t equanity){
        _data += equanity;
        return  *this;
    }

    ReverseVectorIterator& operator - (const ReverseVectorIterator& ptr){
        return *this;
    }
};
#endif // REVERSEVECTORITERATOR_H
