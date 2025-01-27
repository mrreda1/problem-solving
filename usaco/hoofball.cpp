#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "hoofball";


void solve() {
    int n = nxt<int>(), res = 0;
    vector<int> cows(n);
    vector<bool> nav(n + 1);
    nav[0] = nav[n] = 1, nav[n - 1] = 0;
    generate(all(cows), nxt<int>);
    sort(all(cows));

    for (int i = 1; i < n - 1; i++) {
        nav[i] = (cows[i + 1] + cows[i - 1] < 2 * cows[i]);
    }
    for (int i = 0, f = 1, cnt[2]{}; i <= n; i++) {
        if (nav[i] && !f) {
            res += (cnt[0] > 1 && cnt[1] > 1) + 1;
            cnt[0] = cnt[1] = 0;
        }
        cnt[nav[i]]++;
        f = nav[i];
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
