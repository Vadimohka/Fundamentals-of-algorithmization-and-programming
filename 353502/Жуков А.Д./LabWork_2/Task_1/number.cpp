#include "number.h"

Number::Number(const double num)
    : number(num)
{}

double Number::evaluate()
{
    return number;
}
