#ifndef STRINGG_H
#define STRINGG_H

#include "iterator.h"
#include <initializer_list>
#include <memory>

class String
{
    using iterator = Iterator<char>;
    using rIterator = ReverseIterator<char>;
    using cIterator = Iterator<const char>;

    std::unique_ptr<char[]> array;
    size_t size_;
    size_t capacity_;
    
public:
    String();
    explicit String(size_t);
    String(String const&);
    String(std::initializer_list<char>);
    String(const char*);
    ~String();

    char &operator[](size_t);
    String& operator=(const char*);
    String& operator=(String&);
    String& operator=(String&&);
    String operator+(String&);
    String operator+(String&&);
    String& operator+=(String&);
    String& operator+=(String&&);

    template<typename... Args>
    void emplace(cIterator, Args&&...);
    template<typename... Args>
    void emplace_back(Args&&...);
    void insert(cIterator, char const&);
    void insert(cIterator, char&&);
    void push_back(char);

    void assign(size_t, char);
    void assign(cIterator, cIterator);
    void clear();
    void erase(String::iterator);
    void erase(String::iterator, String::iterator);
    void pop_back();

    char &front();
    char &back();
    char &at(size_t);
    char *data();

    size_t capacity() const;
    size_t size() const;
    void resize(size_t, char = char());
    void reserve(size_t);
    bool empty() const;

    iterator begin();
    iterator end();
    rIterator rbegin();
    rIterator rend();

    void swap(String &toSwap);
};

#endif // STRINGG_H