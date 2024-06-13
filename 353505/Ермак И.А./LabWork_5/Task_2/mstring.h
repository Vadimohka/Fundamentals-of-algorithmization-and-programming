#ifndef MSTRING_H
#define MSTRING_H

#include <initializer_list>
#include <memory>
#include <Iterator.h>
class MString
{

public:
    using iterator = Iterator<char>;
    using rIterator = ReverseIterator<char>;
    using cIterator = Iterator<const char>;
    std::unique_ptr<char[]> array;
    size_t size_;
    size_t capacity_;

public:
    MString();
    explicit MString(size_t);
    MString(MString const&);
    MString(std::initializer_list<char>);
    MString(const char*);
    ~MString();

    char &operator[](size_t);
    MString& operator=(const char*);
    MString& operator=(MString&);
    MString& operator=(MString&&);
    MString operator+(MString&);
    MString operator+(MString&&);
    MString& operator+=(MString&);
    MString& operator+=(MString&&);

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
    void erase(MString::iterator);
    void erase(MString::iterator, MString::iterator);
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

    void swap(MString &toSwap);
};

#endif // MSTRING_H
