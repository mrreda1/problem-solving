#include <algorithm>
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;

const bool T = 0;
const string iofile = "balancing";

void solve() {
    int n, b;
    cin >> n >> b;
    int cow[n][2];

    for (int i = 0; i < n; i++) {
        cin >> cow[i][0] >> cow[i][1];
    }
    int res = INT_MAX;
    for (int v = 0; v < n; v++) {
        for (int h = 0; h < n; h++) {
            int x = cow[h][0] + 1, y = cow[v][1] + 1;
            int sum[4]{};
            for (int i = 0; i < n; i++) {
                if (cow[i][0] > x && cow[i][1] > y) {
                    sum[0]++;
                } else if (cow[i][0] > x && cow[i][1] < y) {
                    sum[1]++;
                } else if (cow[i][0] < x && cow[i][1] > y) {
                    sum[2]++;
                } else {
                    sum[3]++;
                }
            }
            sort(sum, sum + 4);
            res = min(res, sum[3]);
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
