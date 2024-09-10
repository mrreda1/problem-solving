#include <algorithm>
#include <iostream>
#include <vector>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
    ll s = 0, e = m - 1, sum = 0, max = 0;
    n--;
    for (ll i = 0; i <= n; i++) {
        ll v[] = {abs(a[i] - b[s]), abs(a[i] - b[e]), abs(a[n] - b[s]),
                  abs(a[n] - b[e])};
        for (int i = 0; i < 4; i++) {
            if (v[i] > v[max])
                max = i;
        }
        sum += v[max];
        if (max == 0 || max == 2) s++;
        else if (max == 1 || max == 3) e--;
        if (max == 2 || max == 3) i--, n--;
    }
    cout << sum;
}

void tsolve();
void io();

int main() {
    io();
    tsolve();
}
void tsolve() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
void io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
