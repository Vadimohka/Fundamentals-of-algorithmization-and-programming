#include "number.h"

Number::Number() {}

Number::Number(double value) : value(value) {}

double Number::evaluate() const {
    return value;
}
