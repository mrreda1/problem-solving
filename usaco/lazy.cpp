#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ld = long double;
using ll = long long;

const bool T = 0;
const string iofile = "lazy";

void solve() {
    ll n = nxt<int>(), k = nxt<int>(), res = 0, sum = 0;
    int field[n][n + 1]{};
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            field[i][j] = field[i][j - 1] + nxt<int>();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++, sum = 0) {
            for (int s = 0; s <= k && i + s < n; s++) {
                sum += field[i + s][j + k - s <= n ? j + k - s : n] -
                       field[i + s][j - k + s < 1 ? 0 : j - k + s - 1];
            }
            for (int s = 1; s <= k && i - s >= 0; s++) {
                sum += field[i - s][j + k - s <= n ? j + k - s : n] -
                       field[i - s][j - k + s < 1 ? 0 : j - k + s - 1];
            }
            res = max(sum, res);
        }
    }
    cout << res;
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
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
