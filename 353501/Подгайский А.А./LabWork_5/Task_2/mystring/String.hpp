    
#ifndef String_LAB4
#define String_LAB4

#include <stdexcept>
#include <limits>
#include <memory>


    class CharDeleter{
        public:
            void operator()(char* p);
    };

    class String {

    public:
        typedef char* iterator;
        typedef const char* const_iterator;

    private:
        std::unique_ptr<char, CharDeleter> data_;
        size_t reserved_ = 0;
        size_t size_ = 0;
        const size_t size_update = 64;

    public:
        explicit String(const char*);
        String();
        String(const String& s);
        String(size_t reserve);
        ~String();

        int size() const;
        int capacity() const;
        bool empty() const;
        size_t max_size() const;

        char back() const;
        char front() const;
        const char * c_str() const;

        void resize(size_t sz, char des);
        void reserve(size_t sz);

        void pop_back();

        void append(const String& s);
        void append(char c);

        void clear();
        void erase(int);

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        char& operator [](size_t x);
        char operator [](size_t x) const;
        char& at(size_t i);
        char at(size_t i) const;
    };

#endif
