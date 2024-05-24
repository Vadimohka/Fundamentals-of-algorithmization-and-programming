#include "deputy.h"

std::string Deputy::to_str() {
    return (author_surname) + ";" + (book_name) + ";" + (book_company) + ";" + std::to_string(book_year) + ";" + std::to_string(page_quantity) + ";"+std::to_string(number) + ";";
}

std::string Deputy::GetAuthor() {
    return author_surname;
}
std::string Deputy::GetBookName() {
    return book_name;
}
std::string Deputy::GetBookCompany() {
    return book_company;
}
int Deputy::GetBookYear() {
    return book_year;
}
int Deputy::GetPageQuantity() {
    return page_quantity;
}
int Deputy::GetId() {
    return id;
}
int Deputy::GetNumber() {
    return number;
}

void Deputy::SetId(int _id) {
    id = _id;
}
