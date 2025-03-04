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
    int n = nxt<int>(), res = 0, mn = INT_MAX;
    vector<int> x(n * 2);
    generate(all(x), nxt<int>);
    sort(all(x));

    for (int a = 0; a < n * 2; a++) {
        for (int b = a + 1; b < n * 2; b++) {
            int sum = 0, i = 0;
            while (i < n * 2) {
                while (i == a || i == b) i++;
                if (i >= n * 2) break;
                sum -= x[i++];
                while (i == a || i == b) i++;
                sum += x[i++];
            }
            mn = min(mn, sum);
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
