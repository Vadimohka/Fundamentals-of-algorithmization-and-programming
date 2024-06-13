//
// Created by shosh on 5/25/24.
//

#include "string.h"


namespace fun {
 void *memcpy(void *s1, const char *s2, size_t n) {
     auto dest = static_cast<char*> (s1);
     auto src = static_cast<const char*>(s2);
     for (int i = 0; i < n; i++) {
         dest[i] = src[i];
     }
     return s1;
 }
 char *strncpy(char *s1, const char *s2, size_t n) {
     for (int i = 0; i < n; i++) {
         s1[i] = s2[i];
         if (s2[i] == '\0') {
             break;
         }
     }
     return s1;
 }
 char *strcpy(char *s1, const char *s2) {
     int i = 0;
     do {
         s1[i] = s2[i];
         i++;
     } while (s2[i] != '\0');
     return s1;
 }

 char *strcat(char *s1, const char *s2) {
     int i = 0;
     for (; s1[i] != '\0'; i++);
     for (int j = i + 1; s2[j - i - 1] != '\0'; j++) {
         s1[i] = s2[i];
     }
     return s1;
 }
 int memcmp(const void *s1, const void *s2, size_t n) {
     auto comp1 = static_cast<const unsigned char*>(s1);
     auto comp2 = static_cast<const unsigned char*>(s2);
     for (int i = 0; i < n; i++) {
         if (comp1[i] < comp2[i]) {
             return -1;
         } else if (comp1[i] > comp2[i]) {
             return 1;
         }
     }
     return 0;
 }
 int strncmp (const char *s1, const char *s2, size_t n) {
     for (int i = 0; i < n; i++) {
         if (s1[i] == '\0' || s2[i] == '\0') {
             if (s1[i] == '\0' && s2[i] != '\0') {
                 return -1;
             } else if (s2[i] == '\0' && s1[i] != '\0') {
                 return 1;
             } else {
                 return 0;
             }
         }
         if (s1[i] < s2[i]) {
             return -1;
         } else if (s1[i] > s2[i]) {
             return 1;
         }
     }
     return 0;
 }

 int strcmp(const char* s1, const char *s2) {
     for (int i = 0; true; i++) {
         if (s1[i] == '\0' || s2[i] == '\0') {
             if (s1[i] == '\0' && s2[i] != '\0') {
                 return -1;
             } else if (s2[i] == '\0' && s1[i] != '\0') {
                 return 1;
             } else {
                 return 0;
             }
         }
         if (s1[i] < s2[i]) {
             return -1;
         } else if (s1[i] > s2[i]) {
             return 1;
         }
     }
 }
 //strcoll sucks, straight up.
 //as well as strxfrm
 size_t strlen (const char* s) {
     size_t length = 0;
     while (*s != '\0') {
         length++;
         s++;
     }
     return length;
 }
 char *strtok(char *searched, char *src) {
     size_t len = strlen(searched);
     for (int i = 0; true; i++) {
         int count = 0;
      if (src[i] == searched[0]) {
          count++;
          for (int j = 1; true; j++) {
              if (count == len) {
                  return &src[i];
              }
              if (searched[j] == src[i + j]) {
                  count++;
                  if (count == len) {
                      return &src[i];
                  }
                  continue;
              }
              if (src[i + j] == '\0') {
                  return nullptr;
              }
              break;
          }
      }
     }
 }
 void *memset(void *s, int c, size_t n)
 {
     unsigned char *p = static_cast<unsigned char*>(s);
     unsigned char u = static_cast<unsigned char>(c);
     for (size_t i = 0; i < n; i++) {
         p[i] = u;
     }
     return s;
 }
}

String::String() {
  data = std::make_unique<char[]>(1);
  data[0] = '\0';
}

String::String(const char *str) {
    size_t initializerSize = fun::strlen(str) + 1;
    data = std::make_unique<char[]>(initializerSize);
    sz = initializerSize;
    cap = initializerSize;
    fun::memcpy(data.get(), str, fun::strlen(str));
}

char &String::operator[](size_t pos) {
    return data[pos];
}

const char &String::operator[](size_t pos) const {
    return data[pos];
}

String::String(const String &str, size_t pos, size_t len) {
   data = std::make_unique<char[]>(len - pos);
   for (size_t i = pos; i < len; i++) {
       data[i - pos] = str[i];
   }
}

String::String(const char *str, size_t n) {
    data = std::make_unique<char[]>(n);
    for (size_t i = 0; i < n; i++) {
        data[i] = str[i];
    }
}

String::String(size_t amount, char symbol) {
   data = std::make_unique<char[]>(amount);
   fun::memset(data.get(), symbol, amount);
    sz = amount;
    cap = amount;
}

String &String::operator=(const String &input) {
    if (&input != this) {
        data = std::make_unique<char[]>(input.sz);
        sz = input.sz;
        cap = sz;
        fun::strcpy(data.get(), input.data.get());
    }
    return *this;
}

String &String::operator=(String &&input) noexcept {
        data = std::move(input.data);
    sz = input.sz;
    cap = sz;
        input.sz = 0;
        input.cap = 0;
        input.resize(0);
    return *this;
}

void String::resize(size_t newSize) {
   if (newSize <= sz) {
       sz = newSize;
       data[sz - 1] = '\0';
   } else {
       reserve(newSize);
       for (size_t i = sz; i < newSize; i++) {
           data[i] = '\0';
       }
       sz = newSize;
   }
}

void String::reserve(size_t newSize) {
   if (newSize <= cap) {
       return;
   }

   std::unique_ptr<char[]> newData = std::make_unique<char[]>(newSize);
   if (sz > 1) {
       fun::memcpy(newData.get(), data.get(), sz);
   }
   data = std::move(newData);
    cap = newSize;
}

bool String::empty() {
    return sz > 1;
}

size_t String::length() {
    if (sz == 0) {
        return 0;
    }
    return (sz - 1);
}

size_t String::size() {
    if (sz == 0) {
        return 0;
    }
    return (sz - 1);
}

String::iterator String::begin() {
    return data.get();
}

String::iterator String::end() {
    return data.get() + sz - 1;
}

