#include <iostream>

void swap(unsigned long long *x, unsigned long long *y) {
    long long temp = *x;
    *x = *y;
    *y = temp;
}
int main () {
    unsigned long long a, b, x, result;
    std::cin >> a >> b >> x;
    if(a > b) swap(&a, &b);
    if((a % x) != 0) a = a - (a % x) + x;
    if((b % x) != 0) b = b - (b % x);
    result = (b - a) / x + 1;
    std::cout << result;
}
