#include <BinaryOperation.h>
#include <Number.h>

bool check_equals(Expression const* left, Expression const* right)
{
    return (*(void**)left == *(void**)right);
}

int main() {
    Expression *n1 = new Number(1);
    Expression *n2 = new Number(2);
    Expression *n3 = new Number(3);
    Expression *n4 = new Number(4);

    Expression *o1, *o2;
    try
    {
        o1 = new BinaryOperation(n1, '-', n2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
        return 0;
    }

    try
    {
        o2 = new BinaryOperation(n3, '/', n4);
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
        return 0;
    }

    std::cout << (check_equals(o1, o2) ? "The same class\n" : "Not the same\n");
    std::cout << (check_equals(n1, o2) ? "The same class\n" : "Not the same\n");

    delete o1;
    delete o2;
}
