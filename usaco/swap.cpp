#include <algorithm>
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "swap";


void solve() {
    int n = nxt<int>(), k = nxt<int>(), m = 0;
    vector<int> cows(n + 1), a(2), b(2);
    iota(all(cows), 0);
    generate(all(a), nxt<int>);
    generate(all(b), nxt<int>);
    do {
        reverse(cows.begin() + a[0], cows.begin() + a[1] + 1);
        reverse(cows.begin() + b[0], cows.begin() + b[1] + 1);
        m++;
    } while (!is_sorted(all(cows)));
    k %= m;
    while (k--) {
        reverse(cows.begin() + a[0], cows.begin() + a[1] + 1);
        reverse(cows.begin() + b[0], cows.begin() + b[1] + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << cows[i] << endl;
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
