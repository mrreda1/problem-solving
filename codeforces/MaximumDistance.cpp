#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;


const bool T = 0;
const string iofile = "";

void solve() {
    ll n, mx{};
    cin >> n;
    int p[n][2];
    for (int i = 0; i < n; i++) {
        cin >> p[i][0];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mx = max(mx, (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) +
                             (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]));
        }
    }
    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (iofile != "") {
        freopen((iofile + ".in").c_str(), "r", stdin);
        freopen((iofile + ".out").c_str(), "w", stdout);
    }
#endif
    if (T) {
        int t;
        cin >> t;
        while (t--) {
            solve();
            cout << '\n';
        }
    } else {
        solve();
    }
}
