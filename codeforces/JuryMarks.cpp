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
    int k = nxt<int>(), n = nxt<int>();
    vector<int> a(k), b(n);
    set<int> res;
    generate(all(a), nxt<int>);
    generate(all(b), nxt<int>);
    sort(all(b));
    for (int i = 0, score; i < k; i++) {
        set<int> valid;
        score = b[0];
        for (int j = i + 1; j < k; j++) {
            score += a[j];
            if (binary_search(all(b), score)) {
                valid.insert(score);
            }
        }
        score = b[0];
        for (int j = i; j >= 0; j--) {
            if (binary_search(all(b), score)) {
                valid.insert(score);
            }
            score -= a[j];
        }
        if (valid.size() == b.size()) {
            res.insert(score);
        }
    }
    cout << res.size();
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
