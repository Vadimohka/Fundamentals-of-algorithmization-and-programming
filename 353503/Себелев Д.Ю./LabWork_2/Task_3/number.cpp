#include "number.h"

Number::Number() {}

Number::Number(double value) : m_value(value) {}

double Number::evaluate()
{
    return m_value;
}
