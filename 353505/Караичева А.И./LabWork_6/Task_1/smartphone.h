#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>

struct Smartphone {
    int release_year;
    int price;
    float diag;
    char eco_class;
    bool IsNew;
    static const int MAX_CHAR_ARRAY_SIZE = 4;
    static const int MAX_INT_ARRAY_SIZE = 3;
    static char mode[MAX_CHAR_ARRAY_SIZE];
    int my_phone_numbers[MAX_INT_ARRAY_SIZE] = {0};

    std::string GetInfo() {
        std::string s = "";
        for (int i = 0; i < MAX_INT_ARRAY_SIZE; i++) {
            s += std::to_string(this->my_phone_numbers[i]);
            if (i != MAX_INT_ARRAY_SIZE - 1) {
                s += ", ";
            }
        }
        std::string str = "";
        for (int i = 0; i < MAX_CHAR_ARRAY_SIZE; i++) {
            str += mode[i];
        }
        return (
            "Year: " + std::to_string(this->release_year) + " | "
            + "Price: " + std::to_string(this->price) + "$ | "
            + "Diag: " + std::to_string(this->diag) + "'' | "
            + "Eco class: " + this->eco_class + " | "
            + "New: " + (this->IsNew ? "true" : "false") + " | "
            + "Numbers: " + s + " | " + "Mode: " + str);
    }
};

#endif // SMARTPHONE_H
