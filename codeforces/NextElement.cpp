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
const string iofile = "";


void solve() {
    int n = nxt<int>();
    vector<int> a(n), res(n);
    generate(all(a), nxt<int>);
    stack<int> ms;
    for (int i = n - 1; i >= 0; i--) {
        while (ms.size() && a[ms.top()] <= a[i]) {
            ms.pop();
        }
        res[i] = ms.size() ? ms.top() : -2;
        ms.push(i);
    }
    int q = nxt<int>();
    while (q--) {
        cout << res[nxt<int>() - 1] + 1 << endl;
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
