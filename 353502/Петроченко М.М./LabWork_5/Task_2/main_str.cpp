#include <iostream>
#include "string.h"

int main() {
    String str1("ABD");
    String str2("AB");
    std::cout << str1.print() << '\n';
    str1.push_back('d');
    std::cout << str1.print() << '\n';
    str1.append(str2);
    std::cout << str1.print() << '\n';
    str1[0] = 'U';
    std::cout << str1.print() << '\n';
    str1.erase(0, 1);
    std::cout << str1.print() << '\n';
    for (char ch : str1) {
        std::cout << ch << '\n';
    }
}
