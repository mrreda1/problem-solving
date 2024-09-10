#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 1;
const string iofile = "";


void solve() {
    int n = nxt<int>(), m = nxt<int>();
    vector<vector<ll>> games(m, vector<ll>(n));
    ll res = 0, prfx[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            games[j][i] = nxt<int>();
        }
    }
    for (vector<ll> &x : games)
        sort(all(x));

    for (int i = 0; i < m; i++) {
        prfx[i][0] = games[i][0];
        for (int j = 1; j < n; j++) {
            prfx[i][j] = prfx[i][j - 1] + games[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            res += prfx[i][n - 1] - prfx[i][j] - games[i][j] * (n - 1 - j);
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
    if (T) {
        int t = nxt<int>();
        while (t--) {
            solve();
            cout << '\n';
        }
    } else {
        solve();
    }
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
