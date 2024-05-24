#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename V> class HashMap {
protected:
  const long UNIHASH_P = 65519;

  struct Entry {
    long key;
    Entry *next;
    V val;

    Entry(long key, Entry *next, const V &val)
        : key(key), next(next), val(val) {}
  };

  size_t hash(long key) { return ((hash_a * key + hash_b) % UNIHASH_P) % size; }

  void init(size_t size) {
    this->size = size;
    entries = new Entry *[size];
    for (int i = 0; i < size; i++) {
      entries[i] = nullptr;
    }

    hash_a = (rand() % (UNIHASH_P - 1) + 1);
    hash_b = rand() % UNIHASH_P;
  }

  void fronAnother(const HashMap &another) {
    size = another.size;
    entries = new Entry *[size];

    hash_a = another.hash_a;
    hash_b = another.hash_b;

    for (int i = 0; i < size; i++) {
      Entry *entr = another.entries[i];
      entries[i] = nullptr;
      while (entr != nullptr) {
        insert(entr->key, entr->val);
        entr = entr->next;
      }
    }
  }

public:
  HashMap(size_t size) { init(size); }

  // TODO: Add constructors, and assignments
  HashMap(const HashMap &another) { fronAnother(another); }

  HashMap &operator=(const HashMap &another) {
    clear();
    delete[] entries;

    fronAnother(another);
    return *this;
  }

  HashMap(HashMap &&another) {
    size = another.size;
    entries = another.entries;
    hash_a = another.hash_a;
    hash_b = another.hash_b;

    another.init(size);
  }

  void clear() {
    for (int i = 0; i < size; i++) {
      Entry *entr = entries[i];
      while (entr != nullptr) {
        Entry *next = entr->next;
        delete entr;
        entr = next;
      }
      entries[i] = nullptr;
    }
  }

  ~HashMap() {
    clear();
    delete[] entries;
  }

  void insert(long key, const V &value) {
    // Could have put at the end slightly more opimally
    // But noooo. Lab says use stack, so stack it is
    remove(key);

    size_t index = hash(key);
    Entry *newe = new Entry(key, entries[index], value);
    entries[index] = newe;
  }

  bool contains(long key) {
    size_t index = hash(key);
    int lim = size;
    Entry *entr = entries[index];
    while (entr != nullptr) {
      if (entr->key == key)
        return true;
      entr = entr->next;
    }

    return false;
  }

  V &get(long key) {
    size_t index = hash(key);
    int lim = size;
    Entry *entr = entries[index];
    while (entr != nullptr) {
      if (entr->key == key)
        return entr->val;
      entr = entr->next;
    }

    throw new std::invalid_argument("Key not found");
  }

  void remove(long key) {
    size_t index = hash(key);
    int lim = size;
    Entry *entr = entries[index];
    Entry **prev_ptr = &entries[index];
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
  Entry **entries;

  // Carter and Wegman Universal hashing
  long long hash_a;
  long long hash_b;
};
