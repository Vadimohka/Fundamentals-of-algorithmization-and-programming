#ifndef MYSTRING_H
#define MYSTRING_H

#include <QDebug>
#include <memory>
#include "iterator.h"
#include <initializer_list>

class MyString
{
    using iterator = Iterator<char>;
    using rIterator = ReverseIterator<char>;
    using cIterator = Iterator<const char>;
public:
    // Конструкторы
    MyString();
    MyString(const MyString&);
    MyString(std::initializer_list<char>);
    MyString(const char*);
    ~MyString();

    // Операторы
    char &operator[](int);
    MyString& operator=(const char*);
    MyString& operator=(MyString&);
    MyString& operator=(MyString&&);
    MyString operator+(MyString&);
    MyString operator+(MyString&&);
    MyString& operator+=(MyString&);
    MyString& operator+=(MyString&&);

    // Методы работы с памятью
    void reserve(int);
    bool empty();
    void resize(int, char = char());
    void clear();

    // Геттеры
    int size() const;
    int capacity() const;

    // Базовые методы
    char &front();
    char &back();
    char &at(int);
    char *data();

    // Получение итераторов
    iterator begin();
    iterator end();
    rIterator rbegin();
    rIterator rend();

    // Метод обмена
    void swap(MyString &b);

    // Дополнительные методы
    void push_back(char);
    template<typename... Args>
    void emplace(cIterator, Args&&...);
    template<typename... Args>
    void emplace_back(Args&&...);

    // Методы изменения диапазона
    void insert(cIterator, const char&);
    void insert(cIterator, char&&);
    void erase(iterator);
    void erase(iterator, iterator);

    // Изменение строки
    void assign(int, char);
    void assign(cIterator, cIterator);

    // Методы работы со строкой
    void pop_back();

    // Функции работы со строками на уровне Си
    static void* memcpy(void* s1, const void* s2, size_t n);
    static void* memmove(void* s1, const void* s2, size_t n);
    static char* strcpy(char* s1, const char* s2);
    static char* strncpy(char* s1, const char* s2, size_t n);
    static char* strcat(char* s1, const char* s2);
    static char* strncat(char* s1, const char* s2, size_t n);
    static int memcmp(const void* s1, const void* s2, size_t n);
    static int strcmp(const char* s1, const char* s2);
    static int strcoll(const char* s1, const char* s2);
    static int strncmp(const char* s1, const char* s2, size_t n);
    static size_t strxfrm(char* s1, const char* s2, size_t n);
    static char* strtok(char* s1, const char* s2);
    static void* memset(void* s, int c, size_t n);
    static char* strerror(int errnum);
    static size_t strlen(const char* s);

private:
    int size_, capacity_;
    std::unique_ptr<char[]> data_;
};

#endif // MYSTRING_H
