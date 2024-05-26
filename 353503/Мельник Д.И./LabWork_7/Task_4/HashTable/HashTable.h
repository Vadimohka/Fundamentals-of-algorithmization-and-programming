
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <sys/types.h>

template <typename T, class Hash> class HashTable {
  using key_t = unsigned long long;

  size_t size_var;
  size_t capacity_var;
  long collisions_var = 0;

  int hash_a, hash_b;

  // a good probing should cover all the elements modulo size of table
  // the given probing works with size of table 2^k
  size_t probe(size_t ind, size_t x) {
    return (ind +  ( (x * (x + 1)) >> 1 )) % capacity_var;
    // return (ind + x) % capacity_var;
  }

  struct node {
    key_t key;
    T val;
    bool taken;
    bool removed;
  };

  node *data;

private:
  void new_node(node *place, key_t key, const T &t) {
    place->key = key;
    new (&place->val) T(t);
    place->taken = true;
    place->removed = false;
  }

  node *_find_ptr(key_t key) {
    const auto ind = Hash::get(key, capacity_var);

    long cnt = 0;
    long i = ind;
    // if we pass item that not marked as removed, we can stop the search
    while (cnt < size_var && (data[i].taken || data[i].removed)) {
      if (data[i].taken && data[i].key == key) {
        return &data[i];
      }

      i = probe(ind, ++cnt);
    }

    return nullptr;
  }

public:
  HashTable(size_t capacity) : capacity_var(capacity) {
    Hash::init();
    size_var = 0;
    data = reinterpret_cast<node *>(new uint8_t[capacity * sizeof(node)]);
    for (int i = 0; i < capacity; ++i) {
      data[i].taken = false;
    }
  }

  ~HashTable() { delete[] data; }

  void clear(){
    for(int i = 0; i < capacity_var; ++i){
      data[i].val.~V();
      data[i].taken = false;
      data[i].removed = false;
    }
    size_var = 0;
  }

  void insert(key_t key, const T &t) {
    auto found = _find_ptr(key);
    if (found) {
      found->val = t;
    } else {
      if (size_var == capacity_var) {
        throw std::runtime_error("Hash table is full");
      }

      ++size_var;
      const long ind = Hash::get(key, capacity_var);
      if (data[ind].taken) {
        ++collisions_var;
      }

      long i = ind;
      long cnt = 0;

      while (data[i].taken) {
        i = probe(ind, ++cnt);
      }
      new_node(&data[i], key, t);
    }
  }

  bool remove(key_t key) {
    auto ind = Hash::get(key, capacity_var);
    auto v = _find_ptr(key);
    if (v) {
      --size_var;
      v->val.~V();
      v->taken = false;
      v->removed = true;
      return true;
    }
    return false;
  }

  T &get(key_t key) {
    auto found = _find_ptr(key);
    if (found)
      return found->val;
    else
      throw std::runtime_error("Element not found");
  }

  bool contains(key_t key) { return _find_ptr(key) != nullptr; }

  long collisions() {return collisions_var;}
};