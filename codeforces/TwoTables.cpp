#include <bits/stdc++.h>
#include <iomanip>

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
    vector<int> r(2), t(2), T(4), b(2), a(2), mn(2);
    generate(all(r), nxt<int>);
    generate(all(T), nxt<int>);
    generate(all(t), nxt<int>);
    b[0] = max(T[0], r[0] - T[2]);
    b[1] = max(T[1], r[1] - T[3]);
    a[0] = min(T[0], r[0] - T[2]);
    a[1] = min(T[1], r[1] - T[3]);
    mn[0] = (a[0] + b[0] >= t[0]) ? (t[0] > b[0] ? t[0] - b[0] : 0) : INT_MAX;
    mn[1] = (a[1] + b[1] >= t[1]) ? (t[1] > b[1] ? t[1] - b[1] : 0) : INT_MAX;
    sort(all(mn));
    cout << (mn[0] == INT_MAX ? -1 : mn[0]);
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
