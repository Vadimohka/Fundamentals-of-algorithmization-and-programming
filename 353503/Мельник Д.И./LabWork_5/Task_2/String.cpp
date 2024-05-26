#include "String.h"
#include <memory>

// memcpy - use String.slice
// memmove - use String.slice
// strcpy - use Copy Constructor/assignment
// strncpy - use String.slice
// strcat - use operator +
// strncat - use operator +
// memcmp - use String.cmp or operators < = > <= =>
// strcmp - use String.cmp or operators < = > <= =>
// strcoll - only C locale supported, use String.cmp or operators < = > <= =>
// strncmp - use slice and String.cmp or operators < = > <= =>
// strxfrm - use assignment
// strtok - use String.tokenize
// memset - use String.fill
// strerror - use String::fromErrno
// strlen - use String.len

String::String() {
  data = std::make_unique<char[]>(1);
  data[0] = 0;
  size = 0;
}

String &String::operator=(const String &other) {
  if (this != &other) {
    fromPtrAndN(other.data.get(), other.size);
  }

  return *this;
}

void String::fromPtrAndN(const char *from, size_t n) {
  size = n;
  data = std::make_unique<char[]>(size + 1);
  for (int i = 0; i < size; i++) {
    data[i] = from[i];
  }
  data[size] = 0;
}

String::String(const char *from) {
  size = 0;

  while (from[size] != 0) {
    size++;
  }

  fromPtrAndN(from, size);
}

size_t String::len() const {
  for(int i = 0; i < size; i++) {
    if(data[i] == 0) return i;
  }
  return size;
}

String String::slice(size_t start, size_t count) const {
  if (start >= size)
    start = size - 1;
  if (count > size - start)
    count = size - start;

  return String(data.get() + start, count);
}

String String::operator+(const String &right) const {
  String res;
  res.size = size + right.size;
  res.data = std::make_unique<char[]>(res.size + 1);

  int pos = 0;

  for (int i = 0; i < size; i++) {
    if (data[i] == 0)
      break;
    res.data[pos++] = data[i];
  }

  for (int i = 0; i < right.size; i++) {
    if (right.data[i] == 0)
      break;
    res.data[pos++] = right.data[i];
  }

  res.data[pos] = 0;
  res.size = pos;
  return res;
}


int String::cmp(const String &right) const {
  for (int pos = 0;; pos++) {
    if (data[pos] != right.data[pos]) {
      return data[pos] < right.data[pos] ? -1 : 1;
    }

    if (data[pos] == '\0') {
      return 0;
    }
  }
  return 0;
}

std::vector<String> String::tokenize(String token) const {
  std::vector<String> res;
  int curS = 0;
  int lim = size;
  for (int i = 0; i < size; i++) {
    char c = data[i];
    if (c == 0) {
      lim = i;
      break;
    }

    bool isToken = false;
    for (int j = 0; j < token.size; j++) {
      if (token[j] == 0)
        break;
      isToken |= token[j] == c;
    }

    if (isToken) {
      if (curS != i) {
        res.push_back(slice(curS, i - curS));
      }
      curS = i + 1;
    }
  }

  if (curS < lim) {
    res.push_back(slice(curS));
  }

  return res;
}

void String::fill(char filler, size_t start, size_t count) {
  if (start >= size)
    start = size - 1;
  if (count > size - start)
    count = size - start;

  for (int i = 0; i < count; i++)
    data[i + start] = filler;
}