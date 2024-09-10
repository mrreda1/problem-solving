#include <iostream>

void solve(long long* c1, long long* c2, long long n) {
    *c1 = *c2 = n/3;
    if (n%3 == 1) (*c1)++;
    else if (n%3 == 2) (*c2)++;
}
int main () {
    int t;
    std::cin >> t;
    while(t--) {
        long long c1, c2, n;
        std::cin >> n;
        solve(&c1, &c2, n);
        std::cout << c1 << ' ' << c2 << '\n';
    }
}
