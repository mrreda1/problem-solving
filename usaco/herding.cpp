#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "herding";


void solve() {
    int mx, mn;
    array<int, 3> cows;
    generate(all(cows), nxt<int>);
    sort(all(cows));
    mx = max(cows[1] - cows[0], cows[2] - cows[1]) - 1;
    mn = min(cows[1] - cows[0], cows[2] - cows[1]) - 1;
    if (mx < 2) {
        cout << mx << endl;
        cout << mx;
    } else {
        cout << (mn == 1 ? 1 : 2) << endl;
        cout << mx;
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
