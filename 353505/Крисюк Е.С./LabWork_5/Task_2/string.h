#ifndef String_H
#define String_H
#include <iostream>

#include <memory>
class String
{
private:
    std::unique_ptr<char[]> data;
    size_t length;
public:

    String();
    explicit String(const char *str);
    String(const String &);

    ~String() = default;
    String &operator=(const String &);

    String &operator=(const char *str);
    size_t size() const;

    const char *c_str() const;

    char &operator[](size_t index);

    const char &operator[](int index) const;

    typedef char *iter;
    typedef const char *const_iter;

    iter begin();

    iter end();
    static void *Memcpy(void *, void *, size_t);

    static void *Memmove(void *, void *, size_t );

    static char *Strcpy(char *, const char *);

    static char *Strncpy(char *, const char *, size_t );

    static char *Strcat(char *, const char *);

    static char *Strncat(char *, const char *, size_t );

    static int Memcmp(const void *, const void *, size_t );

    static int Strcmp(const char *, const char *);

    static int Strcoll(const char *, const char *);

    static int Strncmp(const char *, const char *, size_t );

    static size_t Strxfrm(char *, const char *, size_t );


    static void *Memset(void *, int , size_t );

    static  size_t Strlen(const char *);

    static char *Strchr(const char *, int );

};

#endif // String_H
