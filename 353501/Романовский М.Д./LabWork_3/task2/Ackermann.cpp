#include "Ackermann.h"

int Ackermann::ComputeAckermann(int m, int n) {
  if (m == 0)
    return n + 1;

  if (n == 0)
    return ComputeAckermann(m - 1, 1);

  return ComputeAckermann(m - 1, ComputeAckermann(m, n - 1));
}