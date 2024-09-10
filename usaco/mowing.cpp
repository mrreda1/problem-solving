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
const string iofile = "mowing";

void solve() {
    int s, n, farm[2000][2000]{}, p[2]{1000, 1000}, t{1}, mn{INT_MAX}, *dir, a;
    char d;
    cin >> n;

    while (n--) {
        cin >> d >> s;
        dir = p;
        a = 1;
        switch (d) {
            case 'N':
                a = -1;
            case 'S':
                dir++;
                break;
            case 'W':
                a = -1;
        }
        while (s--) {
            *dir += a;
            if (farm[p[0]][p[1]]) {
                mn = min(mn, t - farm[p[0]][p[1]]);
            }
            farm[p[0]][p[1]] = t++;
        }
    }
    cout << (mn - INT_MAX ? mn : -1);
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
