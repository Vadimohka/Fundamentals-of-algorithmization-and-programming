#include <iostream>

int digits(int n)
{
    if(n == 0)
        return 0;
    return 1 + digits(n / 10);
}

int pow(int n)
{
    if(n == 0)
        return 1;
    return 10 * pow(n - 1);
}

int solution(int n)
{
    int digit = pow(digits(n) - 1);
    if(n / 10 == 0)
        return n;
    return n / digit + 10 * solution(n % digit);
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << solution(n);
    return 0;
}
