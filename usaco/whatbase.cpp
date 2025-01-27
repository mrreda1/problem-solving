#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 1;
const string iofile = "whatbase";


void solve() {
    string n[2] = {nxt<string>(), nxt<string>()};
    ll a[3]{n[0][0] - '0', n[0][1] - '0', n[0][2] - '0'};
    ll b[3]{n[1][0] - '0', n[1][1] - '0', n[1][2] - '0'};
    ll y = 10, ts, x, c;

    do {
        c = b[0] * y * y + b[1] * y + b[2];
        ts = a[1] * a[1] - 4 * a[0] * (a[2] - c);
        if (ts >= 0 && static_cast<int>(sqrt(ts)) == sqrt(ts)) {
            x = (-a[1] + sqrt(ts));
            if (!(x % (2 * a[0])) && x >= 20 * a[0]) {
                cout << x / (2 * a[0]) << ' ' << y;
                return;
            }
        }
    } while (y++);
}

int main() {
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (iofile != "") {
        freopen((iofile + ".in").c_str(), "r", stdin);
        freopen((iofile + ".out").c_str(), "w", stdout);
    }
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << endl);
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
