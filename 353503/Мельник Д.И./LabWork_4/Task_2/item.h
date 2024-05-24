#pragma once

#include <QString>

struct item {
  int val;
  int place;
};

inline item Item(int v) {
  return item{v, 0};
}

inline bool operator<(const item& a, const item& b) {
  return a.val < b.val;
}

inline bool operator>(const item& a, const item& b) {
  return a.val > b.val;
}

inline bool operator==(const item& a, const item& b) {
  return a.val == b.val;
}
