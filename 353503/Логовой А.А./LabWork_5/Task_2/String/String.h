#ifndef STRING_H
#define STRING_H
#include<stdexcept>
#include <memory>
//#include <iterator>

class String {
private:
    std::unique_ptr<char[]> str;
    size_t len;
    size_t _capacity ; // Added capacity for dynamic memory allocation

    typedef char* iterator;
    typedef const char* const_iterator;
    static const size_t npos = static_cast<size_t>(-1);

    void reallocate(size_t new_capacity);

public:

    String();

    String(const char* s);

    String(const String& s);

    String(const char *s, size_t len);

    String& operator=(const String& s);

    String& operator=(const char *s);


    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    size_t capacity() const { return _capacity; }

    void reserve(size_t new_capacity);

    void push_back(char ch);

    void pop_back();

    void append(const char* s);

    String& operator+=(const char* s);

    void* memcpy(void* s1, const void* s2, size_t n);

    void* memmove(void* s1, const void* s2, size_t n);

    char* strcpy(char* s1, const char* s2);

    char* strncpy(char* s1, const char* s2, size_t n);

    char* strcat(char* s1, const char* s2);

    char* strncat(char* s1, const char* s2, size_t n);

    int strcmp(const char* s1, const char* s2);

    int memcmp(const void* s1, const void* s2, size_t n);

    void* memset(void* s, int c, size_t n);

    char* strerror(int errnum);

    int strcoll(const char* s1, const char* s2);

    size_t strxfrm(char* s1, const char* s2, size_t n);

    size_t strlen(const char* s);

    void copy(const char* src, size_t src_pos, size_t count, char* dest);

    bool operator==(const String& other) const;

    bool operator!=(const String& other) const;

    bool operator<(const String& other) const;

    bool operator>(const String& other) const;

    bool operator<=(const String& other) const;

    bool operator>=(const String& other) const;

    char& operator[](size_t pos);

    const char& operator[](size_t pos) const;

    size_t size() const;

    size_t length() const;

    bool empty() const;

    const char* c_str() const;

    char& at(size_t pos);

    const char& at(size_t pos) const;

    String operator+(const String& other) const;

    String& operator+=(const String& other);

    void memset(int c, size_t n);

    size_t strlen() const;

    void clear();

    size_t find(const char* sub, size_t pos = 0) const;


    void insert(size_t pos, const String& other);

    void erase(size_t pos, size_t len = npos);

    void replace(size_t pos, size_t len, const String& other);
};


#endif // STRING_H
