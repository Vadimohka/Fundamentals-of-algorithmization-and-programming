//
// Created by dmitry on 7.4.24.
//

#include "vector.h"

class test{
public:
    test(mySTL::vector<test>* a){
        _a = a;
        std::cout << "class construct " << this  << " lav: " << a << std::endl;
    }
    ~test(){
        std::cout << "class destruct " << this << '\n' << std::endl;
    }
    void print(){
        std::cout << "Hello from class <"  << _a << "> "<< std::endl;
    }
private:
    mySTL::vector<test>* _a;
};

int main (){
    mySTL::vector<test> V(20);
    mySTL::vector<test>* ad = &V;

    for (int i = 0; i < 10; ++i) {
        test _test(ad);
        V.push_back(_test);
    }

    for (int i = 0; i < 10; ++i) {
        V.at(i).print();
    }

    V[4].print();
    std::cout << V.size() << std::endl;

}
