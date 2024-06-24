#ifndef MYSTDSTRING_H
#define MYSTDSTRING_H

#include <iostream>
#include <memory>
#include <cstring>
#include <iterator>
#include <cstring>
#include <limits>

class MyStdString {
public:
    // Конструкторы
    MyStdString();
    MyStdString(const char *str);
    MyStdString(const MyStdString& other);
    MyStdString(size_t reserve);
    ~MyStdString();

    // Методы доступа к размерам
    int my_size() const;
    int my_capacity() const;
    bool my_empty() const;
    size_t my_max_size() const;

    // Методы доступа к символам
    char my_front() const noexcept;
    char my_back() const noexcept;
    const char* my_c_str() const noexcept;

    // Методы изменения размера и емкости
    void my_resize(size_t sz, char def);
    void my_reserve(size_t sz);

    // Методы добавления и удаления символов
    void my_push_back(char c);
    void my_pop_back();

    // Методы добавления и вставки других строк
    void my_append(const MyStdString& other);
    void my_append(char c);
    void my_insert(size_t pos, const char* str);
    void my_insert(size_t pos, const MyStdString& str);
    void my_insert(size_t pos, size_t n, char c);

    // Методы удаления части строки
    void my_clear();
    void my_erase(int x);

    // Итераторы
    typedef char* my_iterator;
    typedef const char* my_const_iterator;

    my_iterator my_begin();
    my_iterator my_end();
    my_const_iterator my_cbegin() const;
    my_const_iterator my_cend() const;

    // Операторы доступа к символам
    char& operator[](size_t x);
    char operator[](size_t x) const;
    char& my_at(size_t x);
    char my_at(size_t x) const;

private:
    std::unique_ptr<char[]> data_;
    size_t reserved_ = 0;
    size_t size_ = 0;
    const size_t size_update = 64;
};

#endif // MYSTDSTRING_H
