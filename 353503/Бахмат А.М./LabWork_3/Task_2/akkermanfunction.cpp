#include "akkermanfunction.h"

AkkermanFunction::AkkermanFunction() {}

unsigned long long AkkermanFunction::akkermanFunction(unsigned long long m, unsigned long long n)
{
    if(m == 0)
    {
        return n + 1;
    }
    else
    {
        if(m > 0 && n == 0)
        {
            return akkermanFunction(m - 1, 1);
        }
        else
        {
            if(m > 0 && n > 0)
            {
                return akkermanFunction(m - 1, akkermanFunction(m, n - 1));
            }
        }
    }

    return 0;
}
