#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <memory>

class String {
private:
    std::unique_ptr<char[]> data;
    size_t length;

public:
    String();

    explicit String(const char *str);

    String(const String &other);

    String &operator=(const String &other);

    String &operator=(const char *str);

    ~String() = default;

    [[nodiscard]] size_t size() const;

    [[nodiscard]] const char *c_str() const;

    char &operator[](size_t index);

    const char &operator[](int index) const;

    typedef char *iterator;
    typedef const char *const_iterator;

    iterator begin();

    iterator end();

    [[nodiscard]] const_iterator begin() const;

    [[nodiscard]] const_iterator end() const;

    String &operator+=(const String &other);

    String &operator+=(const char *str);

    String operator+(const String &other) const;

    bool operator==(const String &other) const;

    bool operator!=(const String &other) const;

    bool operator<(const String &other) const;

    bool operator>(const String &other) const;

    void push_back(const char c);

    static void *Memcpy(void *s1, const void *s2, size_t n);

    static void *Memmove(void *s1, const void *s2, size_t n);

    static char *Strcpy(char *s1, const char *s2);

    static char *Strncpy(char *s1, const char *s2, size_t n);

    static char *Strcat(char *s1, const char *s2);

    static char *Strncat(char *s1, const char *s2, size_t n);

    static int Memcmp(const void *s1, const void *s2, size_t n);

    static int Strcmp(const char *s1, const char *s2);

    static int Strcoll(const char *s1, const char *s2);

    static int Strncmp(const char *s1, const char *s2, size_t n);

    static size_t Strxfrm(char *s1, const char *s2, size_t n);

    static char *Strtok(char *s1, const char *s2);

    static void *Memset(void *s, int c, size_t n);

    static char *Strerror(int errnum);

    static size_t Strlen(const char *s);

    static char *Strchr(const char *str, int c);

    friend std::ostream &operator<<(std::ostream &os, const String &str);
};
#endif // STRING_H
