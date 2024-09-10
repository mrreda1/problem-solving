#include <iostream>

using namespace std;
using llu = unsigned long long;

llu solve1(llu a) {
    llu r = 0;
    for (int i = 0; i <= a; i++) {
        if ((a ^ i) == a - i) {
            r++;
        }
    }
    return r;
}
llu solve2(llu a) {
    llu r = 0;
    while (a) {
        if (a & 1)
            r++;
        a >>= 1;
    }
    return 1<<r;
}

int main() {
    for (int i = 0; i <= 1e8; i++) {
        if (solve1(i) != solve2(i)) {
            cout << i << ' ' << solve1(i) << ' ' << solve2(i) << endl;
        }
    }
}
