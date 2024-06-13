#include "number.h"

Number::Number() : Expression()
{}

Number::~Number()
{

}

Number::Number(double value)
{
    value_ = value;
}

double Number::evaluate()
{
    return value_;
}
