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


ll intersect(const array<ll, 4> &r1, const array<ll, 4> &r2) {
    ll x = max(0ll, min(r1[2], r2[2]) - max(r1[0], r2[0]));
    ll y = max(0ll, min(r1[3], r2[3]) - max(r1[1], r2[1]));
    return x * y;
}
ll area(const array<ll, 4> &r) {
    return (r[2] - r[0]) * (r[3] - r[1]);
}
void solve() {
    array<ll, 4> b1, b2, w;
    generate(all(w), nxt<int>);
    auto readPaper = [&](array<ll, 4> &p) {
        generate(all(p), nxt<int>);
        if (p[0] < w[2]) p[2] = min(p[2], w[2]);
        if (p[1] < w[3]) p[3] = min(p[3], w[3]);
        if (p[2] > w[0]) p[0] = max(p[0], w[0]);
        if (p[3] > w[1]) p[1] = max(p[1], w[1]);
    };
    readPaper(b1), readPaper(b2);
    cout << ((area(w) - intersect(w, b1) - intersect(w, b2) + intersect(b1, b2)) ? "YES" : "NO");
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
