#include <algorithm>
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
    int n = nxt<int>(), mx, crnt;
    vector<int> a(n), suffix(n + 1);
    generate(all(a), nxt<int>);
    suffix[n - 1] = a[n - 1], suffix[n] = a[0];

    for (int i = n - 2; i; i--) {
        suffix[i] = __gcd(a[i], suffix[i + 1]);
    }
    mx = suffix[1], crnt = a[0];
    for (int i = 1; i < n; i++) {
        mx = max(mx, __gcd(suffix[i + 1], crnt));
        crnt = __gcd(crnt, a[i]);
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
