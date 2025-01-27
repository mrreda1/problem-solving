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
    bool rev = 0;
    int n = nxt<int>(), l = 1, r = n, cnt = 0, res = 0;
    vector<int> cows(n + 1), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cows[i] = nxt<char>() == 'G';
        b[i] = (cows[i] && !(i & 1)) + b[i - 1];
        cnt += cows[i];
    }
    do {
        if (!(n & 1)) {
            int f = b[r] - b[l - 1];
            if (rev) f = cnt - f;
            if (cnt > 2 * f) {
                rev = !rev;
                res++;
            }
        }
        cnt -= cows[rev ? l++ : r--];
    } while (--n);
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
