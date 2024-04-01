#include <Number.h>

Number::Number(double x) : Expression()
{
    number = x;
}

double Number::evaluate(){
    return number;
}
