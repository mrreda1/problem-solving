#include <iostream>

int main () {
    long long r, s;
    std::cin >> r >> s;
    std::cout << ((s*s<=2*r*r)?("Circle"):((2*r<=s)?("Square"):("Complex")));
}
