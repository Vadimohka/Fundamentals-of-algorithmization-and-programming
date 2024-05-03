#include "number.h"

Number::Number(double number)
{
    _number = number;
}

double Number::evaluate() const
{
    return _number;
}
