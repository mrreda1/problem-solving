#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "cowtip";


int tip(vector<vector<int>> grid, bool t) {
    int res = t, n = grid.size();
    vector<bool> line(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        bool f = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (t ^ f ^ line[j] ^ grid[i][j]) {
                f = !f;
                res++;
            }
            line[j] = line[j] ^ f;
        }
    }
    return res;
}
void solve() {
    int n = nxt<int>();
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = nxt<char>() - '0';
        }
    }
    cout << min(tip(grid, 1), tip(grid, 0));
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
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
