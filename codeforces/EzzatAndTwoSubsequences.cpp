#include <bits/stdc++.h>
#include <iomanip>

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
    ll n = nxt<ll>();
    double mx = INT_MIN;
    vector<ll> prfx(n + 1, 0), a(n);
    generate(all(a), nxt<ll>);
    sort(all(a));
    for (int i = 1; i <= n; i++) {
        prfx[i] = prfx[i - 1] + a[i - 1];
    }
    for (int i = 1; i < n; i++) {
        double r = i;
        mx = max(mx, (prfx[i] / r) + ((prfx[n] - prfx[i]) / (n - r)));
    }
    cout << fixed << setprecision(9) << mx;
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
