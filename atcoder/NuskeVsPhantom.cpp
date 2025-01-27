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
    int n = nxt<int>() + 1, m = nxt<int>() + 1, q = nxt<int>();
    vector<vector<int>> grid(n, vector<int>(m, 0)), c(n, vector<int>(m, 0)),
        v(n, vector<int>(m, 0)), h(n, vector<int>(m, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] = nxt<char>() - '0';
            h[i][j] = grid[i][j] & grid[i - 1][j];
            v[i][j] = grid[i][j] & grid[i][j - 1];
            c[i][j] = grid[i][j] & grid[i][j - 1] & grid[i - 1][j] &
                      grid[i - 1][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            grid[i][j] += grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
            h[i][j] += h[i][j - 1] + h[i - 1][j] - h[i - 1][j - 1];
            v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
            c[i][j] += c[i][j - 1] + c[i - 1][j] - c[i - 1][j - 1];
        }
    }
    while (q--) {
        array<int, 4> p;
        generate(all(p), nxt<int>);
        cout << (grid[p[2]][p[3]] + grid[p[0] - 1][p[1] - 1] -
                 grid[p[2]][p[1] - 1] - grid[p[0] - 1][p[3]]) -
                    (v[p[2]][p[3]] + v[p[0] - 1][p[1]] - v[p[2]][p[1]] -
                     v[p[0] - 1][p[3]]) -
                    (h[p[2]][p[3]] + h[p[0]][p[1] - 1] - h[p[2]][p[1] - 1] -
                     h[p[0]][p[3]]) +
                    (c[p[2]][p[3]] + c[p[0]][p[1]] - c[p[2]][p[1]] -
                     c[p[0]][p[3]])
             << '\n';
    }
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
