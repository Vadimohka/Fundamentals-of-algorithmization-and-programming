
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <sys/types.h>

template <typename V> class HashTable {


protected:
using key_t = long long;
  const size_t mod = 4096;
  static const long long LARGE_PRIME = 37347127;

  size_t size_var = 0;

  int hash_a, hash_b;

  size_t hash(key_t k){
    return ( (long long) hash_a * k + hash_b) % LARGE_PRIME % mod;
  }

  struct node {
    key_t key;
    V val;
    node * prev = nullptr;
  };

  node **stacks;

private:
  node *new_node(key_t key, const V &v, node * prev) {
    node *nd = reinterpret_cast<node *>(new uint8_t[sizeof(node)]);
    nd->key = key;
    new (&nd->val) V(v);
    nd->prev = prev;
    return nd;
  }

  V * _find_ptr(key_t key) {
    auto ind = hash(key);
    auto item = stacks[ind];
    long cnt = 0;
    // std::cout << "1 :::" << cnt << " ";
    // std::cout << "hhhhh";
    while (item != nullptr) {
      // std::cout << ":::" << cnt << " ";
      // std::cout << "hhhhh";
      if (item->key == key) {
        return &item->val;
      }
      item = item->prev;
      ++cnt;
    }

    return nullptr;
  }

public:
  HashTable(size_t sz = 4096) : mod(sz) {
    stacks = new node*[mod];
    for (int i = 0; i < mod; ++i) {
      stacks[i] = nullptr;
    }

    hash_a = std::rand() % (LARGE_PRIME-1) + 1;
    hash_b = std::rand() % LARGE_PRIME;
  }

  ~HashTable() {
    for (int i = 0; i < mod; ++i) {
      auto cur = stacks[i];
      while (cur != nullptr) {
        delete cur;
        cur = cur->prev;
      }
      stacks[i] = nullptr;
    }
    delete[] stacks;
  }

  void clear(){
    for (int i = 0; i < mod; ++i) {
      auto cur = stacks[i];
      while (cur != nullptr) {
        delete cur;
        cur = cur->prev;
      }
      stacks[i] = nullptr;
    }
    size_var = 0;
  }

  void insert(key_t key, const V &v) {


    // for(int i = 0; i < mod; ++i){
    //   std::cout << stacks[i] << " "; 
    //   if( (size_t)stacks[i] == 0x3c) {
    //     std::cout << "alert!";
    //   }
    // }
    //std::cout << "\n____\n";
    auto found = _find_ptr(key);
    if(found) {
        *found = v;
    } else {
        ++size_var;
        long ind = hash(key);
        stacks[ind] = new_node(key, v, stacks[ind]);
    }
  }

  bool remove(key_t key) {
    auto ind = hash(key);

    auto item = stacks[ind];
    if (!item) {
      return false;
    } else if (item->key == key) {
      --size_var;
      stacks[ind] = item->prev;
      delete item;
      return true;
    } else {
      auto item_parent = item->prev;
      while (item_parent != nullptr) {
        if (item_parent->key == key) {
          auto tmp = item_parent->prev;
          delete item_parent;
          item->prev = tmp;
          return true;
        }

        item = item_parent;
        item_parent = item_parent->prev;
      }
    }
    return false;
  }

  V& get(key_t key) {
    auto found = _find_ptr(key);
    if (found)
      return *found;
    else
      throw std::runtime_error("Element not found");
  }

  bool contains(key_t key) { return _find_ptr(key) != nullptr; }

  size_t size(){ return size_var; }
};