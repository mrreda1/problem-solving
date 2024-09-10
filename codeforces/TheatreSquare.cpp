#include <cmath>
#include <iostream>

int main () {
    double n, m, a;
    std::cin >> n >> m >> a;
    std::cout << (long long) (((long long)ceil(n/a))*ceil(m/a));
}
