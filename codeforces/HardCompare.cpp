#include <cmath>
#include <iostream>

std::string solve() {
    long double A, B, C, D;
    std::cin >> A >> B >> C >> D;
    bool ok = B/D > log(C)/log(A);
    return (ok)?("YES"):("NO");
}
int main () {
    std::cout << solve() << '\n';
}
