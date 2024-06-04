#ifndef SOMESTRING_H
#define SOMESTRING_H
#include <iostream>
#include <memory>
class SomeString
{
private:
    std::unique_ptr<char[]> data;
    size_t length;
public:
    SomeString();
    explicit SomeString(const char *str);
    SomeString(const SomeString &other);

    ~SomeString() = default;
    SomeString &operator=(const SomeString &other);

    SomeString &operator=(const char *str);
    size_t size() const;

    const char *c_str() const;

    char &operator[](size_t index);

    const char &operator[](int index) const;

    typedef char *iter;
    typedef const char *const_iter;

    iter begin();

    iter end();
    static void *SomeMemcpy(void *s1, void *s2, size_t n);

    static void *SomeMemmove(void *s1, void *s2, size_t n);

    static char *SomeStrcpy(char *s1, const char *s2);

    static char *SomeStrncpy(char *s1, const char *s2, size_t n);

    static char *SomeStrcat(char *s1, const char *s2);

    static char *SomeStrncat(char *s1, const char *s2, size_t n);

    static int SomeMemcmp(const void *s1, const void *s2, size_t n);

    static int SomeStrcmp(const char *s1, const char *s2);

    static int SomeStrcoll(const char *s1, const char *s2);

    static int SomeStrncmp(const char *s1, const char *s2, size_t n);

    static size_t SomeStrxfrm(char *s1, const char *s2, size_t n);


    static void *SomeMemset(void *s, int c, size_t n);

    static  size_t SomeStrlen(const char *s);

    static char *SomeStrchr(const char *str, int c);

};

#endif // SOMESTRING_H
