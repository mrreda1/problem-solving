#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";


void solve() {
    ll n = nxt<ll>(), k = nxt<ll>(), mn;
    vector<ll> x(n), desc(n, 0), asc(n, 0);
    generate(all(x), nxt<ll>);
    sort(all(x));
    mn = x[n - 1] - x[0];

    for (int i = 1; i < n; i++) {
        asc[i] = asc[i - 1] + (x[i] - x[i - 1]) * i;
    }
    for (int i = n - 2; i >= 0; i--) {
        desc[i] = desc[i + 1] + (x[i + 1] - x[i]) * (n - i - 1);
    }
    for (int i = lower_bound(all(x), x[n - 1]) - x.begin(); i >= 0;
         i = lower_bound(all(x), x[i - 1]) - x.begin()) {
        if (k < desc[i])
            break;
        ll l, r = desc[i], j = 0, last = x[n - 1], res;
        do {
            l = upper_bound(all(asc), k - r) - asc.begin() - 1;
            res = x[i] - x[l] - j - (k - asc[l] - r) / (l + 1);
            if (res > last)
                break;
            last = res;
            mn = min(mn, res);
            if (mn <= 0) {
                cout << 0;
                return;
            }
            r += n - i;
            j++;
        } while (r <= k && x[i] > x[i - 1] + j);
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
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
