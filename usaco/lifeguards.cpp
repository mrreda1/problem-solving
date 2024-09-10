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
const string iofile = "lifeguards";

void solve() {
    int n, mx = 0;
    cin >> n;
    int a[n][2];
    array<int, 1001> sum{};
    for (int *x : a) {
        cin >> x[0] >> x[1];
        sum[x[0]]++;
        sum[x[1]]--;
    }
    for (int i = 1; i <= 1000; i++) {
        sum[i] += sum[i - 1];
    }
    for (int x = 0; x < n; x++) {
        array<int, 1001> tmp = sum;
        int crnt = 0;
        for (int i = a[x][0]; i < a[x][1]; i++) {
            tmp[i]--;
        }
        for (int i = 0; i <= 1000; i++) {
            if (tmp[i]) crnt++;
        }
        mx = max(mx, crnt);
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
