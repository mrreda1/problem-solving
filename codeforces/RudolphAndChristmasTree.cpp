#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;
using ld = long double;

const bool T = 1;
const string iofile = "";


void solve() {
    ll n = nxt<ll>(), b = nxt<ll>(), h = nxt<ll>(), l = nxt<ll>();
    ld s = b / (2.0 * h), res = n * h * h * s;
    while (--n) {
        ll x = nxt<ll>(), d = h - x + l;
        if (d > 0) res -= d * d * s;
        l = x;
    }
    cout << fixed << setprecision(9) << res;
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
    } while (--t && cout << endl);
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
