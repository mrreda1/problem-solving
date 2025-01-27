#include <algorithm>
#include <bits/stdc++.h>

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
    vector<int> d;
    string s = nxt<string>();
    int res = count(all(s), 'A'), f = s[0], c = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == f) {
            c++;
        } else {
            d.push_back(c * (f == 'A' ? -1 : 1));
            c = 1;
        }
        f = s[i];
    }
    d.push_back(c * (f == 'A' ? -1 : 1));
    sort(all(d));

    if (res == s.size() || !res || s.size() == 1) {
        res = 0;
    } else if (s[0] == 'A' && s.back() == 'A') {
        res += (d.back() > 1 ? 0 : *(lower_bound(all(d), 0) - 1));
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
