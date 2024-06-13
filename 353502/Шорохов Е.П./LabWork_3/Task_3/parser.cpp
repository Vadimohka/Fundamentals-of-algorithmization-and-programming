#include "parser.h"

//I am booored
Parser::Parser() = default;

int64_t Parser::ReverseInt64(int64_t value)
{
    if (value < BASE)
    {
        return value;
    }

    int64_t reversed = ReverseInt64(value / BASE);

    return getPowerOfBaseThatIsGreater(reversed) * (value % BASE) + reversed;
}

int64_t Parser::getPowerOfBaseThatIsGreater(int64_t value)
{
    if (value < BASE)
    {
        return BASE;
    }

    return BASE * getPowerOfBaseThatIsGreater(value / BASE);
}
