#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "art";


void solve() {
    int n = nxt<int>();
    set<int> remain({0});
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> sign(n, vector<int>(n, 0));
    array<bool, 10> valid{};
    array<array<array<int, 2>, 2>, 10> colors;
    fill(all(colors), array<array<int, 2>, 2>(
                          {array<int, 2>({10, 10}), array<int, 2>({-1, -1})}));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = nxt<char>() - '0';
            grid[i][j] = p;
            valid[p] = p;
            remain.insert(p);
            colors[p][0][0] = min(colors[p][0][0], i);
            colors[p][0][1] = min(colors[p][0][1], j);
            colors[p][1][0] = max(colors[p][1][0], i);
            colors[p][1][1] = max(colors[p][1][1], j);
        }
    }
    remain.erase(0);
    do {
        vector<int> toErase;
        for (auto x : remain) {
            array<int, 2> mn(colors[x][0]), mx(colors[x][1]);
            bool skip = false;
            for (int i = mn[0]; i <= mx[0]; i++) {
                for (int j = mn[1]; j <= mx[1]; j++) {
                    if (grid[i][j] && grid[i][j] != x) {
                        skip = true;
                        break;
                    }
                }
                if (skip) {
                    break;
                }
            }
            if (!skip) {
                toErase.push_back(x);
                for (int i = mn[0]; i <= mx[0]; i++) {
                    for (int j = mn[1]; j <= mx[1]; j++) {
                        valid[sign[i][j]] = false;
                        sign[i][j] = x;
                        grid[i][j] = 0;
                    }
                }
            }
        }
        for (int x : toErase) {
            remain.erase(x);
        }
    } while (remain.size());
    cout << count(all(valid), true);
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
