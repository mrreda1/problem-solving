#include <iostream>
#define min(x, y) ((x<y)?(x):(y))

int main () {
    int n, t, i = 1, a[3][5000], sz[3] = {0}, tm;
    std::cin >> n;
    while (i<=n) {
        std::cin >> t;
        a[t-1][sz[t-1]++] = i++;
    }
    tm = min(min(sz[0], sz[1]), sz[2]);
    std::cout << tm << '\n';
    for (i = 0; i < tm; i++) {
        std::cout << a[0][i] << ' ' << a[1][i] << ' ' << a[2][i] << '\n';
    }
}
