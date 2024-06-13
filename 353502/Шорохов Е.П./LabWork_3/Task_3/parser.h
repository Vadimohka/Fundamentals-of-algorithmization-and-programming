#ifndef PARSER_H
#define PARSER_H

//I am booored
#include <cstdint>
#include "math.h"

const int64_t BASE = 10;

class Parser
{
public:
    Parser();
    static int64_t ReverseInt64(int64_t value);
    static int64_t getPowerOfBaseThatIsGreater(int64_t value);
};

#endif // PARSER_H
