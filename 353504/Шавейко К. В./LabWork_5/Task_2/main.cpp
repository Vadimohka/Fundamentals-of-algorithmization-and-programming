#include <QCoreApplication>
#include <QApplication>

#include <iostream>
#include "mystring.h"
#include "mainwindow.h"

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();

    // // Test default constructor
    // String str1;
    // std::cout << "str1: " << str1 << std::endl;

    // // Test constructor with size and character
    // String str2(5, 'A');
    // std::cout << "str2: " << str2 << std::endl;

    // // Test copy constructor
    // String str3 = str2;
    // std::cout << "str3: " << str3 << std::endl;

    // // Test move constructor
    // String str4 = std::move(str3);
    // std::cout << "str4: " << str4 << std::endl;

    // // Test assignment operator
    // String str5;
    // str5 = str4;
    // std::cout << "str5: " << str5 << std::endl;

    // // Test move assignment operator
    // String str6;
    // str6 = std::move(str5);
    // std::cout << "str6: " << str6 << std::endl;

    // // Test size, length, and capacity
    // std::cout << "str6 size: " << str6.size() << std::endl;
    // std::cout << "str6 length: " << str6.length() << std::endl;
    // std::cout << "str6 capacity: " << str6.capacity() << std::endl;

    // // Test clear
    // str6.clear();
    // std::cout << "str6 after clear: " << str6 << std::endl;

    // // Test push_back
    // str6.push_back('X');
    // std::cout << "str6 after push_back: " << str6 << std::endl;

    // // Test pop_back
    // str6.pop_back();
    // std::cout << "str6 after pop_back: " << str6 << std::endl;

    // // Test append
    // str6.append("Hello");
    // std::cout << "str6 after append: " << str6 << std::endl;

    // // Test insert
    // str6.insert(2, " World");
    // std::cout << "str6 after insert: " << str6 << std::endl;

    // // Test erase
    // str6.erase(6, 5);
    // std::cout << "str6 after erase: " << str6 << std::endl;

    // // Test find
    // size_t pos = str6.find("Wor");
    // if (pos != NO_POS) {
    //     std::cout << "Found 'Wor' at position: " << pos << std::endl;
    // } else {
    //     std::cout << "'Wor' not found" << std::endl;
    // }

    // // Test rfind
    // size_t rpos = str6.rfind("o");
    // if (rpos != NO_POS) {
    //     std::cout << "Found 'o' at reverse position: " << rpos << std::endl;
    // } else {
    //     std::cout << "'o' not found" << std::endl;
    // }

    // // Test comparison operators
    // String str7 = "abc";
    // String str8 = "abd";
    // std::cout << "str7 == str8: " << (str7 == str8) << std::endl;
    // std::cout << "str7 != str8: " << (str7 != str8) << std::endl;
    // std::cout << "str7 < str8: " << (str7 < str8) << std::endl;
    // std::cout << "str7 > str8: " << (str7 > str8) << std::endl;
    // std::cout << "str7 <= str8: " << (str7 <= str8) << std::endl;
    // std::cout << "str7 >= str8: " << (str7 >= str8) << std::endl;

    return 0;
}
