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
const string iofile = "div7";

void solve() {
    int n = nxt<int>(), mx = 0;
    vector<ll> cows(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cows[i] = cows[i - 1] + nxt<int>();
    }
    for (int i = n; i; i--) {
        for (int j = 0; j < i; j++) {
            if (!((cows[i] - cows[j]) % 7)) {
                mx = max(mx, i - j);
                break;
            }
        }
    }
    cout << mx;
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
