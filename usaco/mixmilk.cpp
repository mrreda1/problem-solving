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
    int c[3][2], m;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < 100; i++) {
        m = min(c[(i + 1) % 3][0] - c[(i + 1) % 3][1], c[i % 3][1]);
        c[i % 3][1] -= m;
        c[(i + 1) % 3][1] += m;
    }
    for (int i = 0; i < 3; i++) {
        cout << c[i][1] << endl;
    }
}

void tsolve();
void io();
void io(string problem);

int main() {
    io("mixmilk");
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
