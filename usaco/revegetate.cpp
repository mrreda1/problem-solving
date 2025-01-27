#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "revegetate";


void solve() {
    int n = nxt<int>(), m = nxt<int>(), d, t;
    vector<int> fav[n + 1], seed(n + 1, 0);
    while (m--) {
        d = nxt<int>(), t = nxt<int>();
        fav[d].push_back(t);
        fav[t].push_back(d);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!count_if(all(fav[i]), [seed, j](int x) { return seed[x] == j; })) {
                seed[i] = j;
                break;
            };
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << seed[i];
    }
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
