#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 1;
const string iofile = "";


void solve() {
    ll y = nxt<ll>(), x = nxt<ll>();
    if (x >= y) {
        if (x & 1) {
            cout << x * x - y + 1;
        } else {
            cout << (x - 1) * (x - 1) + y;
        }
    } else {
        if (y & 1) {
            cout << (y - 1) * (y - 1) + x;
        } else {
            cout << y * y - x + 1;
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
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
