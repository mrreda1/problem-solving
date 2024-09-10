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

const bool T = 0;
const string iofile = "cownomics";

void solve() {
    int n, m, res = 0;
    char x;
    cin >> n >> m;
    int spotted[n][m], plain[n][m];
    map<char, int> rep = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            spotted[i][j] = rep[x];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            plain[i][j] = rep[x];
        }
    }
    for (int j = 0; j < m; j++) {
        bool skip[4]{};
        for (int i = 0; i < n; i++) {
            skip[spotted[i][j]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (skip[plain[i][j]]) {
                res--;
                break;
            }
        }
        res++;
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
