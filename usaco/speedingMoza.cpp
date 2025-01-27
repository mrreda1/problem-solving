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
    vector<int> roadSpeed(109), bessiSpeed(109);
    int n, m, s, r, ans = 0;
    cin >> n >> m;
    for (int i = 0, cur = 1; i < n; i++) {
        cin >> r >> s;
        roadSpeed[cur] += s, roadSpeed[cur + r] -= s, cur += r;
    }
    for (int i = 0, cur = 1; i < m; i++) {
        cin >> r >> s;
        bessiSpeed[cur] += s, bessiSpeed[cur + r] -= s, cur += r;
    }
    for (int i = 1; i <= 100; i++) {
        roadSpeed[i] += roadSpeed[i - 1], bessiSpeed[i] += bessiSpeed[i - 1],
            ans = max(ans, bessiSpeed[i] - roadSpeed[i]);
    }
    cout << ans;
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
