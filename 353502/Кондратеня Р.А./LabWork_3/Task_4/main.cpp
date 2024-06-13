#include <iostream>

void hanoi(int n, int i, int k)
{
    if(n == 1)
        std::cout << "Move disk " << 1 << " from disk " << i << " to " << k << ". \n";
    else
    {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp);
        std::cout << "Move disk " << n << " from disk " << i << " to " << k << ". \n";
        hanoi(n - 1, tmp, k);
    }
}

int main()
{
    int n;
    std::cin >> n;
    hanoi(n, 1, 3);
    return 0;
}
