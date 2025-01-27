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
const string iofile = "bcount";

void solve() {
    int n = nxt<int>(), q = nxt<int>();
    vector<array<int, 3>> breed(n + 1);
    breed[0] = {0, 0, 0};
    for (int i = 1, j; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            breed[i][j] = breed[i - 1][j];
        }
        breed[i][nxt<int>() - 1]++;
    }
    while (q--) {
        int l = nxt<int>() - 1, r = nxt<int>();
        for (int i = 0; i < 3; i++) {
            cout << breed[r][i] - breed[l][i] << (2 - i ? ' ' : '\n');
        }
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
