#ifndef MY_STRING_H
#define MY_STRING_H

//#include <QDebug>
#include <memory>
#include "iterator.h"
#include <initializer_list>


class my_string
{
    using Conit = iterator<const char>;
    using Normiter = iterator<char>;
    using Reviter = ReverseIterator<char>;

public:
    //Constructors
    my_string();
    my_string(my_string const&);
    my_string(const char*);
    ~my_string();

    //Operators
    char &operator[](int);
    my_string& operator=(const char*);
    my_string& operator=(my_string&);
    my_string& operator=(my_string&&);
    my_string operator+(my_string&);
    my_string operator+(my_string&&);
    my_string& operator+=(my_string&);
    my_string& operator+=(my_string&&);

    //Memory methods
    void reserve(int);
    bool empty();
    void resize(int);
    void clear();

    //Getters
    int size() const;
    int capacity() const;

    //Base
    char &front();
    char &back();
    char &at(int);
    char *data();

    //Iterators
    Normiter begin();
    Normiter end();
    Reviter rbegin();
    Reviter rend();

    //Swap
    void swap(my_string &b);

    //Add functions
    void push_back(char);
    template<typename... Args>
    void emplace(Conit, Args&&...);
    template<typename... Args>
    void emplace_back(Args&&...);

    //Range edit functions
    void insert(Conit, char const&);
    void erase(Normiter);
    void erase(Normiter, Normiter);

    //Change string
    void assign(int, char);
    void assign(Conit, Conit);

    //Pop back
    void pop_back();

    //C functions
    static void* memcpy(void* s1, const void* s2, size_t n);//+
    static void* memmove(void* s1, const void* s2, size_t n);//+
    static char* strcpy(char* s1, const char* s2);//+
    static char* strncpy(char* s1, const char* s2, size_t n);//+
    static char* strcat(char* s1, const char* s2);//+
    static char* strncat(char* s1, const char* s2, size_t n);//+
    static int memcmp(const void* s1, const void* s2, size_t n);//+
    static int strcmp(const char* s1, const char* s2);//+
    static int strcoll(const char* s1, const char* s2);//+
    static int strncmp(const char* s1, const char* s2, size_t n);//+
    static size_t strxfrm(char* s1, const char* s2, size_t n);//+
    static char* strtok(char* s1, const char* s2);//+
    static void* memset(void* s, int c, size_t n);//+
    static char* strerror(int errnum);
    static size_t strlen(const char* s);//+


private:
    int size_=0,capacity_=0;
    std::unique_ptr<char[]>data_=nullptr;
};

#endif // MY_STRING_H
