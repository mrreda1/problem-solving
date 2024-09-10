#include <bits/stdc++.h>
#include <ios>
#include <vector>

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
const string iofile = "";

void solve() { // O(n * log(n))
    int n, v, s, mn{INT_MAX};
    char d;
    vector<int> l, g;
    cin >> n;

    while (n--) {
        cin >> d >> v;
        switch (d) {
            case 'G':
                g.push_back(v);
                break;
            default:
                l.push_back(v);
        }
    }
    sort(all(g));
    sort(all(l));

    s = g.size();
    for (int i = 0; i < s; i++) {
        mn = min(mn, upper_bound(all(l), g[i] + 1) - l.begin() + s - 1 - i);
    }

    s = l.size();
    for (int i = 0; i < s; i++) {
        mn = min(mn, g.end() - lower_bound(all(g), l[i] + 1) + i);
    }

    cout << mn;
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
