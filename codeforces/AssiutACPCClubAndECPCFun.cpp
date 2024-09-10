#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, q, i, l, r, sum = 0, nn = 0;
    cin >> n;

    ll a[n + 1];
    ll skip[n + 2] = {0};

    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        skip[l]++;
        skip[++r]--;
    }
    for (i = 1; i <= n; i++) {
        skip[i] += sum;
        sum = skip[i];
        if (!skip[i]) {
            nn++;
        }
    }
    cout << nn << endl;
    for (i = 1; i <= n; i++) {
        if (!skip[i]) {
            cout << a[i] << ' ';
        }
    }
}

void tsolve();
void io();

int main() {
    io();
    solve();
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
