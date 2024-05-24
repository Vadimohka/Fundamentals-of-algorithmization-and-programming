#include "Search.h"
#include "VisVector.h"

int Search::BinSearch(VisVector *arr, int el, int l, int r) {
  if(r == -100) r = arr->Size();

  int mid = (l + r) / 2;
  int curel = arr->Read(mid);
  if(curel == el) {
    return mid;
  }

  if(l >= r) return -1;

  if(el < curel) {
    return BinSearch(arr, el, l, mid - 1); 
  } else {
    return BinSearch(arr, el, mid + 1, r);
  }
}

int Search::BinSearch(VisVector *arr, int el) {
  return BinSearch(arr, el, 0, arr->Size() - 1);
}

int Search::BinPow(int digit, int power, int mod) {
  if(power == 0) return 1;
  
  if(power % 2 == 1) {
    return digit * BinPow(digit, power - 1, mod) % mod;
  } else {
    int temp = BinPow(digit, power / 2, mod);
    return temp * temp % mod;
  }
}