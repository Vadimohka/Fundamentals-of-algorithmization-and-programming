#include "expression.h"

Expression::Expression() {}

const void *Expression::typeClass() const
{
    return *(reinterpret_cast<const void* const*>(this));
}
