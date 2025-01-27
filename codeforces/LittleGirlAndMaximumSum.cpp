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
const string iofile = "";

void solve() {
    ll n = nxt<int>(), q = nxt<int>(), sum = 0;
    vector<ll> a(n + 1, 0), mul(n + 2, 0);
    generate(1 + all(a), nxt<int>);
    while (q--) {
        mul[nxt<int>()]++;
        mul[nxt<int>() + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        mul[i] += mul[i - 1];
    }
    sort(1 + all(mul) - 1), sort(1 + all(a));
    for (int i = 1; i <= n; i++) {
        sum += a[i] * mul[i];
    }
    cout << sum;
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
