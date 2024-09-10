#include <bits/stdc++.h>
#include <map>

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
const string iofile = "";

void solve() {
    int n, res{};
    cin >> n;
    int a[n + 1];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 2; i <= n; i++) {
        map<int, int> petal;
        ll sum = 0;
        for (int j = 0; j < i; j++) {
            petal[a[j]]++;
            sum += a[j];
        }
        for (int j = 0; j + i <= n; j++) {
            res += (!(sum % i) && petal[sum / i]);
            sum -= a[j];
            petal[a[j]]--;
            sum += a[j + i];
            petal[a[j + i]]++;
        }
    }
    cout << n + res;
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
