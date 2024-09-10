#include <iostream>

void solve() {
    long long a, b, c, d, result;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    a = a % 100;
    b = b % 100;
    c = c % 100;
    d = d % 100;
    result = (a * b * c * d) % 100;
    std::cout << result;
}

int main () {
    solve();
}
