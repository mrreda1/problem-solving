#include <algorithm>
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
    int n = nxt<int>(), m = nxt<int>(), k = nxt<int>();
    vector<ll> a(n + 1), pa(n + 2, 0), pop(m + 2, 0);
    vector<array<ll, 3>> op(m + 1);
    generate(1 + all(a), nxt<int>);
    for (int i = 1; i <= m; i++) {
        generate(all(op[i]), nxt<int>);
    }
    while (k--) {
        pop[nxt<int>()]++;
        pop[nxt<int>() + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        pop[i] += pop[i - 1];
        pa[op[i][0]] += op[i][2] * pop[i];
        pa[op[i][1] + 1] -= op[i][2] * pop[i];
    }
    for (int i = 1; i <= n; i++) {
        pa[i] += pa[i - 1];
        cout << pa[i] + a[i] << ' ';
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
