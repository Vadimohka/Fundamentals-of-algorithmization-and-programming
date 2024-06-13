#include <cstdint>
#include <memory>
#include <vector>
#include "iterator.cpp"

class String {
   private:
    std::unique_ptr<char[]> arr;
    using Iterator = CommonIterator<false>;
    using ConstIterator = CommonIterator<true>;
    uint64_t m_size;
    uint64_t m_capacity;
    static std::vector<uint64_t> kmp(const String&, const String&);
    static std::vector<uint64_t> lps(const String&);

   public:
    String();
    String(uint64_t, char);
    String(const String&);
    String(const char*);
    String& operator=(const String&);
    String& operator=(const char*);

    //element access
    char& operator[](uint64_t);
    char operator[](uint64_t) const;
    char at(uint64_t) const;
    char front() const;
    char back() const;
    char* data();
    const char* c_str() const;

    //iters
    ConstIterator cbegin() const;
    Iterator begin();
    ConstIterator cend() const;
    Iterator end();
    ReverseIterator rbegin();
    ReverseIterator rend();

    //capacity
    bool empty() const;
    uint64_t length() const;
    uint64_t size() const;
    uint64_t max_size() const;
    void reserve(uint64_t);
    uint64_t capacity() const;

    //modifiers
    void clear();
    String& insert(uint64_t, uint64_t, char);
    String& insert(uint64_t, const char*);
    String& insert(uint64_t, const String&);
    String& erase(uint64_t, uint64_t);
    void push_back(char);
    void pop_back();
    String& append(const char*);
    String& append(const String&);
    String& operator+=(const char*);
    String& operator+=(const String&);
    String& replace(uint64_t, const char*);
    String& replace(uint64_t, const String&);
    String& replace(uint64_t, uint64_t, char);
    void resize(uint64_t);
    void swap(String&);

    //search
    uint64_t find(const char*, uint64_t) const;
    uint64_t find(const String&, uint64_t) const;
    uint64_t rfind(const char*, uint64_t) const;
    uint64_t rfind(const String&, uint64_t) const;

    //comparasion
    int compare(const String&) const;
    int compare(const char*) const;
    bool operator==(const String&) const;
    bool operator==(const char*) const;
    bool operator!=(const String&) const;
    bool operator!=(const char*) const;
    bool operator>(const String&) const;
    bool operator>(const char*) const;
    bool operator<(const String&) const;
    bool operator<(const char*) const;

    //misc
    String substr(uint64_t, uint64_t);
    std::string print() const;
    ~String();
};
