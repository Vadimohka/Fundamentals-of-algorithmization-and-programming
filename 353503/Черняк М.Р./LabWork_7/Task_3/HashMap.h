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
      initializeEntries();
      generateHashParameters();
  }

  void initializeEntries() {
      entries = new Entry*[size];
      std::fill(entries, entries + size, nullptr);
  }

  void generateHashParameters() {
      hash_a = (rand() % (UNIHASH_P - 1) + 1);
      hash_b = rand() % UNIHASH_P;
  }

  void copyFrom(const HashMap& another) {
      size = another.size;
      initializeEntries();
      copyHashParameters(another);
      copyEntries(another);
  }

  void copyHashParameters(const HashMap& another) {
      hash_a = another.hash_a;
      hash_b = another.hash_b;
  }

  void copyEntries(const HashMap& another) {
      for (size_t i = 0; i < size; i++) {
          copyLinkedList(another.entries[i], entries[i]);
      }
  }

  void copyLinkedList(const Entry* src, Entry*& dst) {
      while (src != nullptr) {
          insert(src->key, src->val);
          src = src->next;
      }
  }

public:
  HashMap(size_t size) { init(size); }

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

  void insert(long key, const V& value) {
      size_t index = hash(key);
      Entry* newEntry = new Entry(key, entries[index], value);
      entries[index] = newEntry;
  }

  bool contains(long key) {
      size_t index = hash(key);
      Entry* entry = entries[index];
      while (entry != nullptr) {
          if (entry->key == key) {
              return true;
          }
          entry = entry->next;
      }
      return false;
  }

  V& get(long key) {
      Entry* entry = findEntry(key);
      if (entry == nullptr) {
          throw std::invalid_argument("Key not found");
      }
      return entry->val;
  }

  void remove(long key) {
      size_t index = hash(key);
      Entry** prevPtr = &entries[index];
      Entry* curr = *prevPtr;

      while (curr != nullptr) {
          if (curr->key == key) {
              *prevPtr = curr->next;
              delete curr;
              return;
          }
          prevPtr = &curr->next;
          curr = *prevPtr;
      }
  }

  Entry* findEntry(long key) {
      size_t index = hash(key);
      Entry* curr = entries[index];

      while (curr != nullptr) {
          if (curr->key == key) {
              return curr;
          }
          curr = curr->next;
      }

      return nullptr;
  }

  void rehash(size_t new_size) {
      // Create a new array of entries with the new size
      Entry **new_entries = new Entry *[new_size];
      for (size_t i = 0; i < new_size; i++) {
          new_entries[i] = nullptr;
      }

      // Save old entries and size
      Entry **old_entries = entries;
      size_t old_size = size;

      // Update size and entries to new ones
      entries = new_entries;
      size = new_size;

      // Rehash all entries
      for (size_t i = 0; i < old_size; i++) {
          Entry *entr = old_entries[i];
          while (entr != nullptr) {
              Entry *next = entr->next;
              size_t new_index = hash(entr->key);
              entr->next = new_entries[new_index];
              new_entries[new_index] = entr;
              entr = next;
          }
      }

      // Delete old entries array
      delete[] old_entries;
  }


protected:
  size_t size;
  Entry **entries;

  // Carter and Wegman Universal hashing
  long long hash_a;
  long long hash_b;
};
