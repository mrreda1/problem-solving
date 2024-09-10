#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    ll x, y, z, k, cnt = 0;
    cin >> x >> y >> z >> k;
    for (ll i = 1; i <= x; i++) {
        for (ll j = 1; j <= y; j++) {
            ll w = k / (i * j);
            if (w <= z && i * j * w == k) {
                cnt++;
            }
        }
    }
    cout << cnt;
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
