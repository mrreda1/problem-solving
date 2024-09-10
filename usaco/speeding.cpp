#include <iostream>

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

void solve() {
    int n, m, mx = 0, r, s = 0, i;
    cin >> n >> m;
    int sig[n][2], walked, lim;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> sig[i][j];
        }
    }

    for (walked = lim = i = 0; walked < 100; i++) {
        lim += sig[i][0];
        while (lim > walked) {
            cin >> r >> s;
            walked += r;
            mx = max(mx, s - sig[i][1]);
        }
        mx = max(mx, s - sig[i][1]);
    }
    cout << mx;
}

void tsolve();
void io();
void io(string problem);

int main() {
    io("speeding");
    solve();
}
void tsolve() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
void io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#endif
}
void io(string problem) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#endif
#ifndef _DEBUG
    string in = problem + ".in";
    string out = problem + ".out";
    freopen(in.c_str(), "r", stdin);
    freopen(out.c_str(), "w", stdout);
#endif // !_DEBUG
}
