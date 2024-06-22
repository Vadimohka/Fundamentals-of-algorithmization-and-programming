#include "number.h"

Number::Number() {}

Number::Number(double number) : number(number)
{

}

Number::~Number() = default;

void Number::SetNumber(double number)
{
    number = number;
}

double Number::GetNumber()
{
    return number;
}

double Number::count()
{
    return number;
}
