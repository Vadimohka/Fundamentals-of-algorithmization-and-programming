#include "binaryoperation.h"
#include "number.h"

int main()
{
    Expression *first = new BinaryOperation(new Number(2.5), '+', new Number(4.5));
    Expression *second = new BinaryOperation(new Number(150), '+', first);
    std::cout << second->evaluate() << '\n';
    delete first;
    delete second;
}
