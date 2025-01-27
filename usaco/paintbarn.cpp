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
const string iofile = "paintbarn";

void solve() {
    ll barn[1003][1003]{{}};
    int n = nxt<int>(), k = nxt<int>(), res = 0;
    while (n--) {
        array<int, 4> p;
        generate(all(p), nxt<int>);
        barn[++p[1]][++p[0]]++;
        barn[++p[3]][++p[2]]++;
        barn[p[1]][p[2]]--;
        barn[p[3]][p[0]]--;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            barn[i][j] += barn[i - 1][j] + barn[i][j - 1] - barn[i - 1][j - 1];
            res += (barn[i][j] == k);
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
