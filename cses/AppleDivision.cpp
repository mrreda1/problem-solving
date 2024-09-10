#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    int x;
    vector<ll> a, subset;
    ll n, sm = 0, mn = LLONG_MAX;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        sm += x;
        a.push_back(x);
    }

    function<void(int)> bruteForce = [&](int k) {
        if (k == n) {
            ll crnt = 0;
            for (ll i : subset) {
                crnt += a[i];
            }
            mn = min(mn, abs(sm - crnt * 2));
        } else {
            bruteForce(k + 1);
            subset.push_back(k);
            bruteForce(k + 1);
            subset.pop_back();
        }
    };
    bruteForce(0);
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
