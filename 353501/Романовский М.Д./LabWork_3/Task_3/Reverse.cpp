#include "Reverse.h"

long long Reverse::ReverseDigits(long long x, long long acc) {
  if (x == 0)
    return acc;
  long long d = x % 10;
  return ReverseDigits(x / 10, acc * 10 + d);
}

long long Reverse::CountDigits(long long x) {
  if (x == 0)
    return 0;
  return CountDigits(x / 10) + 1;
}