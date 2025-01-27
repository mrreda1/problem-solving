#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    const int n = 8;
    vector<bool> occupied_column(n, 0), occupied_diagonal(2 * n, 0),
        occupied_revdiagonal(2 * n, 0);
    char chess[n][n];
    int res = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> chess[y][x];
        }
    }
    function<void(int)> checkMate = [&](int y) {
        if (y == n) {
            res++;
            return;
        }
        for (int x = 0; x < n; x++) {
            if (chess[y][x] == '*') {
                continue;
            }
            bool ok = !(occupied_column[x] || occupied_diagonal[y + x] ||
                        occupied_revdiagonal[y - x + n]);
            if (ok) {
                occupied_column[x] = occupied_diagonal[y + x] =
                    occupied_revdiagonal[y - x + n] = true;
                checkMate(y + 1);
                occupied_column[x] = occupied_diagonal[y + x] =
                    occupied_revdiagonal[y - x + n] = false;
            }
        }
    };
    checkMate(0);
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
