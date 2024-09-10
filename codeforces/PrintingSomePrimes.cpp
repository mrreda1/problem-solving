#include <iostream>

void io() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // DEBUG
}
int main() {
    io();
    bool isprime;
    int n = 1e8, i, cnt = 0, j;
    for (i = 2; i < n; i++) {
        for (j = 2, isprime = true; j*j <= i; j++) {
            if (!(i%j)) {
                isprime = false;
                break;
            }
        }
        if (isprime && !((cnt++)%100)) {
            std::cout << i << '\n';
        }
    }
}
