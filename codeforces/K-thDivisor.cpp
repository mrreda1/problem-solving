#include <cmath>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, k, i, divs;
    cin >> n >> k;
    for (i = 1, divs = 0; i * i <= n; i++) {
        if (!(n % i) && k == ++divs) {
            cout << i;
            return;
        }
    }
    divs *= 2;
    if (ll(sqrt(n)) * ll(sqrt(n)) == n)
        --divs;
    if (k > divs)
        cout << -1;
    for (i = 1; i * i < n; i++) {
        if (!(n % i) && k == divs--) {
            cout << n / i;
            return;
        }
    }
}


void tsolve();
void io();

int main() {
    io();
    solve();
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
