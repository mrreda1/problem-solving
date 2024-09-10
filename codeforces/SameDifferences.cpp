#include <iostream>
typedef unsigned long long llu;

llu solve() {
    llu n, x, i, cnt = 0;
    std::cin >> n;
    unsigned a[2*n] = {0};
    for(i = 0; i < n; i++) {
        std::cin >> x;
        a[x - i + n - 2]++;
    }
    for(i = 0; i < 2*n; i++)
        cnt+=(((llu)a[i])*(a[i]-1))/2;
    return cnt;
}
int main() {
    unsigned t;
    std::cin >> t;
    while(t--)
        std::cout << solve() << '\n';
}
