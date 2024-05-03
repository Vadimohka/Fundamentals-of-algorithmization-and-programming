#include "Reverser.h"
#include <cmath>

unsigned long Reverser::p_reverse(unsigned long num, unsigned long rem) {
  if (num == 0) {
    return rem;
  }
  return p_reverse(num/10L, 10L*rem + num%10L);
}

long Reverser::reverse(long num) {
  bool neg = (num < 0L);
  long res = p_reverse(std::abs(num), 0);
  if(neg){
    res = -res;
  }
  return res;
}