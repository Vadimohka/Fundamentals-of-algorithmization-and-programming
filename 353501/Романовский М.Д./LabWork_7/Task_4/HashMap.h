#include <cstddef>
#include <cstdlib>
#include <stdexcept>

template <typename V> class HashMap {
private:
  const long UNIHASH_P = 65519;

  struct Key {
    long key;
    bool taken;
  };

  size_t hash(long key) { return ((hash_a * key + hash_b) % UNIHASH_P) % size; }

  void init(size_t size) {
    this->size = size;
    collisons = 0;
    keys = new Key[size];
    for (int i = 0; i < size; i++) {
      keys[i].taken = false;
    }
    values = (V *)new unsigned char[size * sizeof(V)];

    hash_a = (rand() % (UNIHASH_P - 1) + 1);
    hash_b = rand() % UNIHASH_P;
  }

  void fronAnother(const HashMap &another) {
    size = another.size;
    collisons = another.collisons;
    keys = new Key[size];
    values = (V *)new unsigned char[size * sizeof(V)];

    hash_a = another.hash_a;
    hash_b = another.hash_b;

    for (int i = 0; i < size; i++) {
      if (another.keys[i].taken) {
        keys[i].key = another.keys[i].key;
        keys[i].taken = true;
        new (&values[i]) V(another.values[i]);
      } else {
        keys[i].taken = false;
      }
    }
  }

public:
  HashMap(size_t size) { init(size); }

  // TODO: Add constructors, and assignments
  HashMap(const HashMap &another) { fronAnother(another); }

  HashMap &operator=(const HashMap &another) {
    clear();
    delete[] keys;
    delete[] (unsigned char *)values;

    fronAnother(another);
    return *this;
  }

  HashMap(HashMap &&another) { 
    size = another.size;
    collisons = another.collisons;
    keys = another.keys;
    values = another.values;
    hash_a = another.hash_a;
    hash_b = another.hash_b;

    another.init(size);
  }

  void clear() {
    for (int i = 0; i < size; i++) {
      if (keys[i].taken) {
        values[i].~V();
        keys[i].taken = false;
      }
    }
  }

  ~HashMap() {
    clear();
    delete[] keys;
    delete[] (unsigned char *)values;
  }

  void insert(long key, const V &value) {
    size_t index = hash(key);
    int lim = size;
    while (keys[index].taken) {
      if(keys[index].key == key) {
        break;
      }
      
      collisons++;

      index++;
      if (index >= size)
        index = 0;

      lim--;
      if (lim == 0)
        return;
    }

    keys[index].key = key;
    keys[index].taken = true;
    new (&values[index]) V(value);
  }

  bool contains(long key) {
    size_t index = hash(key);
    int lim = size;

    while (keys[index].taken) {
      if (keys[index].key == key)
        return true;

      index++;
      if (index >= size)
        index = 0;

      lim--;
      if (lim == 0)
        return false;
    }

    return false;
  }

  V &get(long key) {
    size_t index = hash(key);
    int lim = size;

    while (keys[index].taken) {
      if (keys[index].key == key)
        return values[index];

      index++;
      if (index >= size)
        index = 0;

      if (lim == 0)
        break;
    }

    throw new std::invalid_argument("Key not found");
  }

  size_t getCollisionCount(bool reset = false) {
    int ret = collisons;
    if(reset) collisons = 0;
    return ret;
  }

private:
  size_t size;
  size_t collisons;
  Key *keys;
  V *values;

  // Carter and Wegman Universal hashing
  long long hash_a;
  long long hash_b;
};
