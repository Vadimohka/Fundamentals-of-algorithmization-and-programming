#include "checkequals.h"

bool check_equals(Expression const* left, Expression const* right) {
    return *(void**)left == *(void**)right;
}
