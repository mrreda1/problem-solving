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
const string iofile = "";

void solve() {
    ll n = nxt<int>(), res = n + 1;
    vector<vector<int>> grid(n + 2, vector<int>(n + 2, 0));
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {nxt<int>(), nxt<int>()};
    }
    auto compress = [&p, n]() {
        sort(all(p));
        for (int i = 1; i <= n; i++) {
            p[i - 1][0] = i;
            swap(p[i - 1][0], p[i - 1][1]);
        }
    };
    compress(), compress();
    for (auto [x, y] : p) {
        grid[x][y] = 1;
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            array<int, 4> c{min(p[i][0], p[j][0]), max(p[i][0], p[j][0]),
                            min(p[i][1], p[j][1]), max(p[i][1], p[j][1])};
            ll l = grid[c[1]][c[2]] - grid[c[0] - 1][c[2]],
               h = grid[c[1]][n] - grid[c[0] - 1][n] - grid[c[1]][c[3] - 1] +
                   grid[c[0] - 1][c[3] - 1];
            res += h * l;
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
