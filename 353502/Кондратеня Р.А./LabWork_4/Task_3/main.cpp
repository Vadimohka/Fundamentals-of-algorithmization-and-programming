#include <iostream>
#include <cmath>
#include <vector>

int findMiddle(int a, int b, int c)
{
    int max = std::max(a, std::max(b, c));
    int min = std::min(a, std::min(b, c));
    return a + b + c - min - max;
}

int main()
{
    std::vector<int> input, output;
    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::cout << "Enter your array: ";
    for(int i = 0; i < n; ++i)
    {
        int m;
        std::cin >> m;
        input.push_back(m);
    }
    for(int i = 0; i < n; i *= 3)
        output.push_back(findMiddle(input[i], input[i + 1], input[i + 2]));
    if(n % 3 == 2)
        output.push_back((input[n - 1] + input[n - 2]) / 2);
    if(n % 3 == 1)
        output.push_back(input[n - 1]);
    int length = output.size();
    for(int i = 0; i < length; ++i)
        std::cout << output[i] << " ";
    return 0;
}
