#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class HashMap {
protected:
  const long UNIHASH_P = 65519;

  struct Element {
    long key;
    Element *next;
    T val;

    Element(long key, Element *next, const T &val)
        : key(key), next(next), val(val) {}
  };

  size_t hash(long key) {
    return key % size; 
  }

  void init(size_t size) {
    this->size = size;
    elements = new Element *[size];
    for (int i = 0; i < size; i++) {
      elements[i] = nullptr;
    }
  }

  void fronAnother(const HashMap &another) {
    size = another.size;
    elements = new Element *[size];

    for (int i = 0; i < size; i++) {
      Element *entr = another.elements[i];
      elements[i] = nullptr;
      while (entr != nullptr) {
        insert(entr->key, entr->val);
        entr = entr->next;
      }
    }
  }

public:
  HashMap(size_t size) { init(size); }

  
  HashMap(const HashMap &another) { fronAnother(another); }

  
  HashMap &operator=(const HashMap &another) {
    clear();
    delete[] elements;

    fronAnother(another);
    return *this;
  }

  HashMap(HashMap &&another) {
    size = another.size;
    elements = another.elements;

    another.init(size);
  }

  void clear() {
    for (int i = 0; i < size; i++) {
      Element *entr = elements[i];
      while (entr != nullptr) {
        Element *next = entr->next;
        delete entr;
        entr = next;
      }
      elements[i] = nullptr;
    }
  }

  ~HashMap() {
    clear();
    delete[] elements;
  }

  
  void insert(long key, const T &value) {
    remove(key);

    size_t index = hash(key);
    Element *newe = new Element(key, elements[index], value);
    elements[index] = newe;
  }

  
  bool contains(long key) {
    size_t index = hash(key);
    Element *entr = elements[index];
    while (entr != nullptr) {
      if (entr->key == key)
        return true;
      entr = entr->next;
    }

    return false;
  }

  
  T &get(long key) {
    size_t index = hash(key);
    Element *entr = elements[index];
    while (entr != nullptr) {
      if (entr->key == key)
        return entr->val;
      entr = entr->next;
    }

    throw std::invalid_argument("Key not found");
  }


  void remove(long key) {
    size_t index = hash(key);
    Element *entr = elements[index];
    Element **prev_ptr = &elements[index];
    while (entr != nullptr) {
      if (entr->key == key) {
        *prev_ptr = entr->next;
        delete entr;
        return;
      }
      prev_ptr = &entr->next;
      entr = entr->next;
    }
  }

protected:
  size_t size;
  Element **elements;
};
