#ifndef CONSTVECTORITEARATOR_H
#define CONSTVECTORITEARATOR_H
#include<cstddef>

template<typename T>
class ConstVectorIterator{

private:
    T* _data;

public:
    explicit ConstVectorIterator(T* data) : _data(data) {}

    bool operator >= (const ConstVectorIterator&ptr) const {
        return _data >= ptr._data;
    }

    bool operator <= (const ConstVectorIterator&ptr) const {
        return _data <= ptr._data;
    }

    bool operator < (const ConstVectorIterator&ptr) const {
        return _data < ptr._data;
    }

    bool operator > (const ConstVectorIterator&ptr) const {
        return _data > ptr._data;
    }

    bool operator == (const ConstVectorIterator&ptr) const {
       return _data == ptr._data;
    }

    bool operator != (const ConstVectorIterator&ptr) const {
       return _data != ptr._data;
    }

    T& operator *() const {
        return *_data;
    }

    const ConstVectorIterator&  operator++ (){
        _data++;
        return _data;
    }

    const ConstVectorIterator& operator-- (){
        _data--;
        return _data;
    }

    const ConstVectorIterator& operator +=(size_t equanity){
        _data += equanity;
        return _data;
    }

    const ConstVectorIterator& operator -=(size_t equanity){
        _data -= equanity;
        return _data;
    }

    const ConstVectorIterator& operator - (const ConstVectorIterator& ptr){
        return _data - ptr;

    }
};
#endif // CONSTVECTORITEARATOR_H
