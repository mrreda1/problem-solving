#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;


const bool T = 0;
const string iofile = "traffic";

void solve() {
    int n, s, e;
    string t;
    cin >> n;
    int traf[n][3];

    for (int i = 0; i < n; i++) {
        cin >> t >> traf[i][0] >> traf[i][1];
        if (t == "on") {
            traf[i][2] = 1;
        } else if (t == "off") {
            traf[i][2] = -1;
        } else {
            traf[i][2] = 0;
        }
    }
    s = 0, e = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        switch (traf[i][2]) {
            case 0:
                s = max(s, traf[i][0]);
                e = min(e, traf[i][1]);
                break;
            case 1:
                s -= traf[i][1];
                e -= traf[i][0];
                s = max(s, 0);
                e = max(e, 0);
                break;
            case -1:
                s += traf[i][0];
                e += traf[i][1];
        }
    }
    cout << s << ' ' << e << endl;

    s = 0, e = 1e9;
    for (int i = 0; i < n; i++) {
        switch (traf[i][2]) {
            case 0:
                s = max(s, traf[i][0]);
                e = min(e, traf[i][1]);
                break;
            case -1:
                s -= traf[i][1];
                e -= traf[i][0];
                s = max(s, 0);
                e = max(e, 0);
                break;
            case 1:
                s += traf[i][0];
                e += traf[i][1];
        }
    }
    cout << s << ' ' << e;
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
