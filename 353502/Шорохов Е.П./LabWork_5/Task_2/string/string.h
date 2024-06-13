//
// Created by shosh on 5/25/24.
//

#ifndef LABWORK_5_STRING_H
#define LABWORK_5_STRING_H

#include <memory>


class String {
private:
    std::unique_ptr<char[]> data;
    size_t sz = 0;
    size_t cap = 1;

    using iterator = char*;
    using const_iterator = const char*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    String();
    explicit String(const char *str);
    String(const String& str, size_t pos, size_t len);
    String(const char* str, size_t n);
    String(size_t amount, char symbol);
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const;
    String& operator=(const String& input);
    String& operator=(String &&input) noexcept ;
    void resize(size_t newSize);
    void reserve(size_t size);
    bool empty();
    size_t length();
    size_t size();
    iterator begin();
    iterator end();
};


#endif //LABWORK_5_STRING_H
