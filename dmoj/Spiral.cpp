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
    int n = nxt<int>(), m = nxt<int>(), k = nxt<int>();
    vector<vector<int>> grid(n, vector<int>(m, INT_MAX));
    while (k--) {
        int x = nxt<int>() - 1, y = nxt<int>() - 1,
            s[2]{-1, nxt<int>() ? -1 : 1}, mark = 1, cnt = 2;
        grid[x][y] = 1;
        for (int i = 1; mark < m * n; i++) {
            for (int j = 0; j < i; j++, cnt++) {
                x += s[0];
                if (x < n && y < m && (x | y) >= 0) {
                    grid[x][y] = min(cnt, grid[x][y]);
                    mark++;
                }
            }
            for (int j = 0; j < i; j++, cnt++) {
                y += s[1];
                if (x < n && y < m && (x | y) >= 0) {
                    grid[x][y] = min(cnt, grid[x][y]);
                    mark++;
                }
            }
            s[0] = (s[0] == 1 ? -1 : 1);
            s[1] = (s[1] == 1 ? -1 : 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
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
