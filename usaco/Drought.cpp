#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ld = long double;
using ll = long long;

const bool T = 1;
const string iofile = "";

void solve() {
    ll n = nxt<int>(), res = 0, amx, amn = 1e9;
    vector<int> a(n);
    for (int &x : a) {
        x = nxt<int>();
        res += x;
        amn = min(static_cast<int>(amn), x);
    }
    do {
        for (int i = 0; i < n - 1; i++) {
            auto [mn, mx] = minmax_element(a.begin() + i, a.begin() + i + 2);
            *mx -= *mn - amn;
            *mn = amn;
        }
        if (a[0] > amn || a[n - 1] > amn) {
            cout << -1;
            return;
        }
        amx = *max_element(all(a));
        amn -= amx - amn;
    } while (amx != amn && amn >= 0);
    cout << (amn < 0 ? -1 : res - amn * n);
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
