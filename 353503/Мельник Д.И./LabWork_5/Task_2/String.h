#include <memory>
#include <vector>

class String {
public:
  String();
  String(const String &str) { fromPtrAndN(str.data.get(), str.size); };
  ~String() {};

  String &operator=(const String &other);

  String(const char *from, size_t n) { fromPtrAndN(from, n); };
  String(const char *from);

  const char *c_str() const { return data.get(); };
  char *c_str() { return data.get(); };

  char operator[](size_t pos) const { return data[pos]; };
  char &operator[](size_t pos)  { return data[pos]; };

  size_t len() const;

  String slice(size_t start = 0, size_t count = SIZE_MAX) const;
  String operator+(const String &right) const;

  int cmp(const String &right) const;
  bool operator<(const String &right) const { return cmp(right) < 0; }
  bool operator>(const String &right) const { return cmp(right) > 0; }
  bool operator==(const String &right) const { return cmp(right) == 0; }
  bool operator!=(const String &right) const { return cmp(right) != 0; }
  bool operator<=(const String &right) const { return cmp(right) <= 0; }
  bool operator>=(const String &right) const { return cmp(right) >= 0; }

  std::vector<String> tokenize(String tokens) const;

  void fill(char filler, size_t start = 0, size_t count = SIZE_MAX);

private:
  void fromPtrAndN(const char *from, size_t n);

  std::unique_ptr<char[]> data;
  int size;
};