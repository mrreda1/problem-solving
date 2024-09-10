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
    int n = nxt<int>(), res = 0;
    array<vector<int>, 2> lines;
    for (int i = 0; i < n; i++) {
        int x = nxt<int>(), y = nxt<int>();
        lines[y].push_back(x);
    }
    sort(all(lines[0]));
    sort(all(lines[1]));
    for (int x : lines[0]) {
        if (binary_search(all(lines[1]), x)) {
            res += n - 2;
        }
        if (binary_search(all(lines[1]), x - 1) &&
            binary_search(all(lines[1]), x + 1)) {
            res++;
        }
    }
    for (int x : lines[1]) {
        if (binary_search(all(lines[0]), x - 1) &&
            binary_search(all(lines[0]), x + 1)) {
            res++;
        }
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
