#include <algorithm>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, k, q, d, i;
    cin >> n >> k >> q;
    ll a[k + 1], b[k + 1];
    a[0] = b[0] = 0;
    for (i = 1; i <= k; i++)
        cin >> a[i];
    for (i = 1; i <= k; i++)
        cin >> b[i];
    while (q--) {
        cin >> d;
        if (d) {
            i = lower_bound(a, a + k + 1, d) - a;
            double s = (double(a[i] - a[i - 1])) / (b[i] - b[i - 1]);
            cout << int((d - a[i - 1])/s) + b[i - 1] << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
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
