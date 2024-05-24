#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "Iterator.h"
#include <typeinfo>
#include "Vector.h"


class MyClass{
private:
    int a;
    bool c;
public:
    std::string b = "vfddfv";
};

template<typename T>
void print(Vector<T>& a){
    for(size_t i = 0; i <= a.Capacity(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

template<typename T>
void printSize(Vector<T>& a){
    for(size_t i = 0; i <= a.Size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}


int main(int argc, char *argv[])
{
    Vector<int> a;
    a.push_back(4);
    print(a);
    printSize(a);   
    std::cout << a.at(1) << "\n";
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    print(a);
    printSize(a);
    a.reserve(3);
    print(a);
    printSize(a);
    a.at(1);
    a.resize(10);
    print(a);
    printSize(a);
    a.at(0);
    size_t capacity = a.Capacity();
    std::cout << capacity << "\n";
    size_t size = a.Size();
    std::cout << size << "\n";
    std::cout << a.max_size() << "\n";
    std::cout << &a.front() << "\n";
    std::cout << &a.back() << "\n";
    a.assign(5, 3);
    print(a);
    printSize(a);
    //std::cout << a.begin() << "\n";
    //std::cout << a.end() << "\n";
    std::cout << a.begin().getIteratorAddress() << "\n";
    std::cout << a.end().getIteratorAddress() << "\n";

    Vector<int>::iterator it = a.begin();
    std::cout << it.getIteratorAddress() << "\n";
    ++it;
    std::cout << it.getIteratorAddress() << "\n";
    it++;
    std::cout << it.getIteratorAddress() << "\n"; 

    std::cout << a.empty() << "\n";
    std::cout << a[0] << "\n";
    a.insert(2, 6);
    a.insert(4, 7);
    printSize(a);
    std::cout << *a.begin() << "\n";
    a.erase(a.begin(), a.begin() + 2);
    printSize(a);
}
