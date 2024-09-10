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
    char c;
    int b[2], l[2], r[2], res;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            switch (c) {
                case 'B':
                    b[0] = i;
                    b[1] = j;
                    break;
                case 'L':
                    l[0] = i;
                    l[1] = j;
                    break;
                case 'R':
                    r[0] = i;
                    r[1] = j;
            }
        }
    }
    res = abs(l[1] - b[1]) + abs(l[0] - b[0]) - 1;
    if (l[0] == b[0]) {
        res = abs(l[1] - b[1]) +
              (l[0] == r[0] && ((r[1] - l[1]) ^ (r[1] - b[1])) < 0) * 2 - 1;
    } else if (l[1] == b[1]) {
        res = abs(l[0] - b[0]) +
              (l[1] == r[1] && ((r[0] - l[0]) ^ (r[0] - b[0])) < 0) * 2 - 1;
    }
    cout << res;
}

void tsolve();
void io();
void io(string problem);

int main() {
    io("buckets");
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
