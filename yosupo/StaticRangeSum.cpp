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
    int n = nxt<int>(), q = nxt<int>();
    vector<ll> partialSum(n);
    partialSum[0] = nxt<int>();

    for (int i = 1; i < n; i++) {
        partialSum[i] = partialSum[i - 1] + nxt<int>();
    }
    while (q--) {
        int l = nxt<int>(), r = nxt<int>();
        cout << partialSum[r - 1] - (l ? partialSum[l - 1] : 0) << '\n';
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
