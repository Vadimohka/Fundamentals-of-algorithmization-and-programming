#include "number.h"

Number::Number(double number)
{
    _number = number;
}

double Number::evaluate()
{
    return _number;
}
