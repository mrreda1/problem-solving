#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ld = long double;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    string s = ' ' + nxt<string>();
    int q = nxt<int>(), n = s.size();
    vector<array<int, 26>> preFreq(n);
    preFreq[0] = {};
    for (int i = 1; i < n; i++) {
        preFreq[i] = preFreq[i - 1];
        preFreq[i][s[i] - 'a']++;
    }
    while (q--) {
        int l = nxt<int>(), r = nxt<int>();
        if (s[l] != s[r] || l == r) {
            cout << "YES\n";
        } else {
            int freq = 0;
            for (int i = 0; i < 26; i++) {
                freq += (preFreq[r][i] != preFreq[l - 1][i]);
            }
            cout << ((freq > 2) ? "YES" : "NO") << '\n';
        }
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
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
