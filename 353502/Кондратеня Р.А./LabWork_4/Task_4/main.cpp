#include "Vector.h"
#include <iostream>

int main(){
    Vector<std::string> abc;

    abc.push_back("qewwef");
    abc.push_back("qwefwe");
    abc.push_back("wefwef");

    bool b = abc.begin() == abc.end();

    std::cout << b << " ";
    std::cout<< abc[0] << " " << abc[1] << " " <<abc[2] << " ";
}
