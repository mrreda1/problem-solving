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
    ll n = nxt<int>(), k = nxt<int>(), res = 0;
    vector<ll> a(n), b(n);
    a[0] = nxt<int>();

    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] + nxt<int>();
    }
    for (int i = 0, mx = 0; i < n; i++) {
        mx = max(nxt<int>(), mx);
        b[i] = mx;
    }
    for (int i = 0; i < min(k, n); i++) {
        res = max(res, a[i] + b[i] * (k - 1 - i));
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
