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
    ll n = nxt<ll>(), k = nxt<ll>(), res = 0;
    vector<vector<ll>> field(2 * n, vector<ll>(2 * n, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            field[j + i - 1][n - i + j] = nxt<ll>();
        }
    }
    n *= 2, k *= 2;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            field[i][j] +=
                field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            res = max(res, field[i][j] - field[i - k < 1 ? 0 : i - k - 1][j] -
                               field[i][j - k < 1 ? 0 : j - k - 1] +
                               field[i - k < 1 ? 0 : i - k - 1]
                                    [j - k < 1 ? 0 : j - k - 1]);
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
