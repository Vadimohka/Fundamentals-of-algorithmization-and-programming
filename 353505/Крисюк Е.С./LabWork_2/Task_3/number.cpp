#include "number.h"

Number::Number() {

}

Number::Number(double num)
{
    number = num;
}

double Number::evaluate()
{
    return number;
}
