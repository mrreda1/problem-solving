#include <iostream>
#include <algorithm>
#include <limits>

typedef unsigned long long llu;

void solve() {
    unsigned n, si, ei, i;
    llu x, start, end, diff;
    std::cin >> n;
    llu h[n];
    for(i = 0; i < n; i++) {
        std::cin >> x;
        h[i] = x;
    }
    std::sort(h, h + n);
    diff = std::numeric_limits<llu>::max();
    for(i = 0; i < n - 1; i++) {
        if(h[i + 1] - h[i] < diff) {
            start = h[i];
            si = i;
            end = h[i + 1];
            ei = i + 1;
            diff = end - start;
        }
    }
    std::cout << h[si] << ' ';
    for(i = ei + 1; i < n; i++)
        std::cout << h[i] << ' ';
    for(i = 0; i < si; i++)
        std::cout << h[i] << ' ';
    std::cout << h[ei] << ' ';
}
int main() {
    unsigned t;
    std::cin >> t;
    while(t--) {
        solve();
        std::cout << '\n';
    }
}
