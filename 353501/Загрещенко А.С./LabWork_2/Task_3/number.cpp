#include "number.h"

Number::Number(double val) : value(val) {}

double Number::evaluate() const
{
    return value;
}

