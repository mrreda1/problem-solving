#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "triangles";

void solve() {
    int n, mx = 0;
    cin >> n;
    int a[n][2];
    set<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        p.insert({a[i][0], a[i][1]});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((p.count({a[i][0], a[j][1]}) || p.count({a[j][0], a[i][1]}))) {
                mx = max(mx, abs((a[i][0] - a[j][0]) * (a[i][1] - a[j][1])));
            }
        }
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
