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
    map<int, vector<int>> a;
    int n = nxt<int>(), k = nxt<int>();
    for (int i = 0; i < n; i++) {
        a[nxt<int>()].push_back(i + 1);
    }
    for (auto x : a) {
        int diff = k - x.first;
        if (a.count(diff)) {
            vector<int> y = a[diff];
            if (diff == x.first) {
                if (y.size() > 1) {
                    cout << y[0] << ' ' << y[1];
                    return;
                }
            } else if (y.size() > 0) {
                cout << x.second[0] << ' ' << y[0];
                return;
            }
        }
    }
    cout << -1;
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
