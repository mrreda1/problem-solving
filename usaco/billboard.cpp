#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "billboard";


int intersect(array<array<int, 4>, 2> r) {
    int x = max(0, min(r[0][2], r[1][2]) - max(r[0][0], r[1][0]));
    int y = max(0, min(r[0][3], r[1][3]) - max(r[0][1], r[1][1]));
    return x * y;
}
int area(array<int, 4> r) {
    return (r[2] - r[0]) * (r[3] - r[1]);
}
void solve() {
    array<array<int, 4>, 3> r;
    for (auto &p : r)
        generate(all(p), nxt<int>);
    cout << area(r[0]) - intersect({r[0], r[2]}) + area(r[1]) -
                intersect({r[1], r[2]});
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
