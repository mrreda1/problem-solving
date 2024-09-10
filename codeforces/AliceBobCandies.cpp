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
    int n = nxt<int>(), steps = 1, l = 1, r = n - 1, c = n - 1;
    bool crnt = 0;
    vector<int> a(n);
    generate(all(a), nxt<int>);
    array<int, 2> eat{a[0], 0}, last{a[0], 0};
    while (c) {
        crnt = !crnt;
        if (crnt) {
            last[1] = 0;
            while (c && last[1] <= last[0]) {
                last[1] += a[r--];
                c--;
            }
            eat[1] += last[1];
        } else {
            last[0] = 0;
            while (c && last[0] <= last[1]) {
                last[0] += a[l++];
                c--;
            }
            eat[0] += last[0];
        }
        steps++;
    }
    cout << steps << ' ' << eat[0] << ' ' << eat[1];
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
