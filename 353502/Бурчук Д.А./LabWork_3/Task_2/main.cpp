#include <iostream>

int AkkermanFunction(unsigned long long m, unsigned n) {
    if(!m) {
        return n +1;
    } else if(!n) {
        return AkkermanFunction(m - 1, 1);
    } else {
        return AkkermanFunction(m - 1, AkkermanFunction(m, n - 1));
    }
}

int main() {
    int n;
    int m;
    std::cin >> m >> n;
    std::cout << AkkermanFunction(m,n) << std::endl;
    return 0;
}
