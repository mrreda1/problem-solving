#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "citystate";


void solve() {
    int n = nxt<int>(), res = 0;
    map<string, vector<string>> states;
    while (n--) {
        string city = nxt<string>();
        states[nxt<string>()].push_back(city.substr(0, 2));
    }
    for (auto [state, cities] : states) {
        for (string city : cities) {
            if (city != state) {
                res += count(all(states[city]), state);
            }
        }
    }
    cout << res / 2;
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
