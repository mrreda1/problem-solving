#include <iostream>
#include <algorithm>

int main () {
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
    unsigned n, i;
    std::cin >> n;
    unsigned long long a[n];
    for(i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] *= 1e6;
        a[i] += i + 1;
    }
    std::sort(a, a + n);
    for(i = 0; i < n; i++)
        std::cout << a[i]%((unsigned)1e6) << ' ';
}
