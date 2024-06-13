#include <iostream>

int function(int m, int n)
{
    if(m == 0)
        return n + 1;
    if(m > 0 && n == 0)
        return function(m - 1, 1);
    if(m > 0 && n > 0)
        return function(m - 1, function(m, n - 1));
}

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::cout << function(m ,n);
    return 0;
}
