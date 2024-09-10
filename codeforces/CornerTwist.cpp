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


const bool T = 1;
const string filename = "";

void solve() {
    int n, m;
    char c;
    cin >> n >> m;
    int dst[n][m], trgt[n][m];

    // Inputs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            dst[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            trgt[i][j] = c - '0';
        }
    }

    // Check each index one by one
    // till you make dst same as trgt
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dst[i][j] != trgt[i][j]) {
                if (i == n - 1 || j == m - 1) {
                    cout << "NO";
                    return;
                } else {
                    while (dst[i][j] != trgt[i][j]) {
                        dst[i][j] = (dst[i][j] + 1) % 3;
                        dst[i + 1][j + 1] = (dst[i + 1][j + 1] + 1) % 3;
                        dst[i + 1][j] = (dst[i + 1][j] + 2) % 3;
                        dst[i][j + 1] = (dst[i][j + 1] + 2) % 3;
                    }
                }
            }
        }
    }
    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (filename != "") {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
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
