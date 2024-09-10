#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "angry";


void solve() {
    int n = nxt<int>(), res = 1;
    vector<int> hays(n);
    generate(all(hays), nxt<int>);
    sort(all(hays));
    for (int i = 0, l, r, x, tmp; i < n; i++) {
        x = 1, l = r = i;
        while (l >= 0) {
            tmp = lower_bound(all(hays), hays[l] - x++) - hays.begin();
            if (tmp == l) break;
            l = tmp;
        }
        x = 1;
        while (r < n) {
            tmp = upper_bound(all(hays), hays[r] + x++) - hays.begin() - 1;
            if (tmp == r) break;
            r = tmp;
        }
        res = max(res, 1 + r - l);
    }
    cout << res;
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
