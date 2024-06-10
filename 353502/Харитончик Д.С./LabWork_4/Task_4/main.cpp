#include "vector_iterator/vector.h"
#include <iostream>

int main()
{
    Vector<std::string > abc;

    abc.push_back("jhvvds");
    abc.push_back("vnsdjkv");
    abc.push_back("jkfbhwejhh");

    bool b = abc.begin() == abc.end();

    std::cout << b << " ";
    std::cout << abc[0] << " " << abc[1] << " " << abc[2] << " ";
}
