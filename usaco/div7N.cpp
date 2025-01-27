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
const string iofile = "div7";

void solve() {
    ll n = nxt<ll>(), mx = 0;
    vector<ll> rim(7, -1), cows(n + 1);
    rim[0] = cows[0] = 0;
    for (int i = 1; i <= n; i++) {
        cows[i] = cows[i - 1] + nxt<ll>();
        if (rim[cows[i] % 7] == -1) {
            rim[cows[i] % 7] = i;
        }
    }
    for (int i = n; i; i--) {
        mx = max(mx, i - rim[cows[i] % 7]);
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
