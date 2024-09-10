#include <algorithm>
#include <iostream>
#include <numeric>

std::string solve() {
    int n, x, cnt = 0;
    std::cin >> n;
    n *= 2;
    while(n--) {
        std::cin >> x;
        (x%2)?(cnt++):(cnt--);
    }
    if(cnt) return "NO";
    return "YES";
}
int main () {
    int t;
    std::cin >> t;
    while(t--) {
        std::cout << solve() << '\n';
    }
}
