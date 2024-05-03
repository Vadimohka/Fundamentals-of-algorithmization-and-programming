#ifndef ITERATOR_H
#define ITERATOR_H
template <typename T>
class iterator
{

public:

    iterator(){
        this->pointer=pointer;
    };
protected:
    T* pointer;
public:
    T operation_take(){
        return pointer;
    };
    T opertion_increment(){
        pointer++;
    };
    T operation_decrement(){
        pointer--;
    };
    bool good_compare(T*t1,T*t2){
        if(t1==t2) return true;
        else return false;
    };
    bool bad_compare(T*t1,T*t2){
        if(t1!=t2) return true;
        else return false;
    }
    T move_r_n(int n){
        pointer+=n;
        return pointer;
    }
    T move_l_n(int n){
        pointer-=n;
        return pointer;
    }
    T diff_iterator(T*t1,T*t2){
        return t1;
    }
};

#endif // ITERATOR_H
