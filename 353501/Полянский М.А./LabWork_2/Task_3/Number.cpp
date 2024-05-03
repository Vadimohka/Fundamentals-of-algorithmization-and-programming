#include "Number.h"

Number::Number(double val) : value(val) {}

double Number::evaluate() const {
    return value;
}

Number::~Number() {}
