#include <iostream>
#include <string>

std::string decimalToBinary(int n) {
    if (n == 0) {
        return "0";
    } else if (n == 1) {
        return "1";
    } else {
        return decimalToBinary(n / 2) + std::to_string(n % 2);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::string ans = decimalToBinary(n);
    std::cout << ans;
    return 0;
}
