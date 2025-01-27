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
const string iofile = "hps";

void solve() {
    int n = nxt<int>(), mx = 0;
    vector<array<int, 3>> moves(n + 1);
    moves[0] = {};
    for (int i = 1; i <= n; i++) {
        char x = nxt<char>();
        for (int j = 0; j < 3; j++) {
            moves[i][j] = moves[i - 1][j];
        }
        moves[i][(x == 'P' ? 0 : (x == 'H' ? 1 : 2))]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            mx =
                max(mx, moves[i][j] +
                            max(moves[n][(j + 1) % 3] - moves[i][(j + 1) % 3],
                                moves[n][(j + 2) % 3] - moves[i][(j + 2) % 3]));
        }
    }
    cout << mx;
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
