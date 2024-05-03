#include "number.h"

Number::Number(double value)
    : m_value(value)
{
}

Number::~Number()
{
}

double Number::evaluate() const
{
    return m_value;
}
