#pragma once

#include <experimental/random>
#include "item.h"

class Distributor {
 public:
  Distributor(int size, item* array);
  void flip(int, int);
  void Dregular();
  void Duniform();
  void Dcentered();
  void Dsplit();
  void Dhigh();
  void Dlow();
  void Srandom();
  void Ssorted();
  void Sreversed();
  void Sshuffle();

 private:
  int m_size;
  item* m_array;
};
