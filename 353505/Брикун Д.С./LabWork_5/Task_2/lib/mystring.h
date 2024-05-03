#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <memory>
class myString {
private:
    std::unique_ptr<char[]> data;
    size_t length;

public:
	myString regex_search(const char* pattern) const {
			std::regex regexPattern(pattern);
			std::cmatch match;

			if (std::regex_search(data.get(), match, regexPattern)) {
				return myString(match.str().c_str());
			} else {
				return myString("");
			}
		}

    myString();

    explicit myString(const char *str);

    myString(const myString &other);

    myString &operator=(const myString &other);

    myString &operator=(const char *str);

    ~myString() = default;

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

    myString &operator+=(const myString &other);

    myString &operator+=(const char *str);

    myString operator+(const myString &other) const;

    bool operator==(const myString &other) const;

    bool operator!=(const myString &other) const;

    bool operator<(const myString &other) const;

    bool operator>(const myString &other) const;

    void push_back(const char c);

    static void *myMemcpy(void *s1, const void *s2, size_t n);

    static void *myMemmove(void *s1, const void *s2, size_t n);

    static char *myStrcpy(char *s1, const char *s2);

    static char *myStrncpy(char *s1, const char *s2, size_t n);

    static char *myStrcat(char *s1, const char *s2);

    static char *myStrncat(char *s1, const char *s2, size_t n);

    static int myMemcmp(const void *s1, const void *s2, size_t n);

    static int myStrcmp(const char *s1, const char *s2);

    static int myStrcoll(const char *s1, const char *s2);

    static int myStrncmp(const char *s1, const char *s2, size_t n);

    static size_t myStrxfrm(char *s1, const char *s2, size_t n);

    static char *myStrtok(char *s1, const char *s2);

    static void *myMemset(void *s, int c, size_t n);

    static char *myStrerror(int errnum);

    static size_t myStrlen(const char *s);

    static char *myStrchr(const char *str, int c);

    friend std::ostream &operator<<(std::ostream &os, const myString &str);
};
#endif // MYSTRING_H
