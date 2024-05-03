#include "expression.h"

Expression::Expression() = default;

const void *Expression::my_type_id() const
{
    return *(reinterpret_cast<const void* const*>(this));
}
