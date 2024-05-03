#include "swapanimator.h"

SwapAnimator::SwapAnimator() {}

void SwapAnimator::swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
