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
const string iofile = "reduce";

void solve() {
    int n = nxt<int>(), mn = INT_MAX;
    vector<array<int, 2>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        x[i][0] = y[i][1] = nxt<int>();
        x[i][1] = y[i][0] = nxt<int>();
    }
    sort(all(x)), sort(all(y));
    for (auto &cow : y) reverse(all(cow));
    for (int pr[3]{0}; pr[0] < 4; pr[0]++) {
        for (pr[1] = 0; pr[1] < 4; pr[1]++) {
            for (pr[2] = 0; pr[2] < 4; pr[2]++) {
                int px[2]{0, n - 1}, py[2]{0, n - 1};
                set<array<int, 2>> rm;
                for (int i = 0; i < 3; i++) {
                    rm.insert((pr[i] & 1 ? y : x)[(pr[i] & 1 ? py : px)[pr[i] > 1]]);
                    while (rm.count(x[px[0]])) px[0]++;
                    while (rm.count(x[px[1]])) px[1]--;
                    while (rm.count(y[py[0]])) py[0]++;
                    while (rm.count(y[py[1]])) py[1]--;
                }
                mn = min(mn, (x[px[1]][0] - x[px[0]][0]) * (y[py[1]][1] - y[py[0]][1]));
            }
        }
    }
    cout << mn;
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
