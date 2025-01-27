#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ld = long double;
using ll = long long;

const bool T = 1;
const string iofile = "";

void solve() {
    int n = nxt<int>(), res = 0;
    vector<int> a(n), preMax(n, 0), postMax(n, 0);
    generate(all(a), nxt<int>);
    for (int i = 1; i < n - 1; i++) {
        preMax[i] = max(preMax[i - 1], a[i - 1]) - 1;
    }
    for (int i = n - 2; i; i--) {
        postMax[i] = max(postMax[i + 1], a[i + 1]) - 1;
    }
    for (int i = 1; i < n - 1; i++) {
        res = max(res, a[i] + postMax[i] + preMax[i]);
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
    } while (--t && cout << '\n');
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
