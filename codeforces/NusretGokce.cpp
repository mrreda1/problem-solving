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
    int n = nxt<int>(), m = nxt<int>();
    vector<int> a(n + 1), prefix(n + 2, 0), suffix(n + 2, 0);
    generate(1 + all(a), nxt<int>);
    for (int i = 1; i <= n; i++) {
        prefix[i] = max(prefix[i - 1] - m, a[i]);
    }
    for (int i = n; i; i--) {
        suffix[i] = max(suffix[i + 1] - m, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << max(suffix[i], prefix[i]) << ' ';
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
