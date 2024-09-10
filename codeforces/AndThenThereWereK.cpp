#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    // ll x, i, y;
    // cin >> x;
    // y = ((1LL << int(log2(x) + 1)) - 1) ^ x;
    // bitset<64> yb = y;
    // for (i = 0; i < 64; i++) {
    //     if (!yb[i]) {
    //         if (1LL << i < x - y) {
    //             y += 1LL << i;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // cout << y;
    int n;
    cin >> n;
    int k = 1;
    while (k <= n) {
        k <<= 1;
    }
    cout << (k - 1) / 2 << endl;
}

void tsolve();
void io();

int main() {
    io();
    tsolve();
}
void tsolve() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
void io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
