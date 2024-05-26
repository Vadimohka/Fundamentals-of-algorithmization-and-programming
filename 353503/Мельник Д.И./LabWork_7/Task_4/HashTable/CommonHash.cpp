#include "CommonHash.h"
#include <bit>
#include <cmath>

long UniversalHash::hash_a = 1  ;
long UniversalHash::hash_b = 0;
size_t ModuloHash::get(size_t x, size_t sz) {
  return x % sz;
}

size_t UniversalHash::get(long long x, size_t sz) {
  return ( ((long long)hash_a * x + hash_b) % PRIME ) % sz;
}

void UniversalHash::init() {
  hash_a = std::rand() % (UniversalHash::PRIME - 1) + 1;
  hash_b = std::rand() % (UniversalHash::PRIME);
}
