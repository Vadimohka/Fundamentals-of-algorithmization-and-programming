#include "Hanoi.h"
#include <qcontainerfwd.h>

QList<QPair<int, int>> Hanoi::Solve(long long x, int from, int aux, int to) {
  if (x == 0)
    return {};

  QList<QPair<int, int>> res;
  res.append(Solve(x - 1, from, to, aux));
  res.push_back({from, to});
  res.append(Solve(x - 1, aux, from, to));

  return res;
}