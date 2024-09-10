#include <algorithm>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    llu n, m, i, freq[1001] = {0}, mx = 0, mn = 0;
    cin >> n >> m;
    llu a[m], s, sum = 0;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(a, a + m);

    for (i = 0, s = n; i < m; i++) {
        if (s <= a[i]) {
            mn += a[i] * (a[i] + 1) / 2 - (a[i] - s) * (a[i] - s + 1) / 2;
            break;
        }
        s -= a[i];
        mn += a[i] * (a[i] + 1) / 2;
    }

    for (i = 1000, s = n; i; i--) {
        freq[i] += sum;
        sum = freq[i];
        if (freq[i] >= s) {
            mx += s * i;
            break;
        }
        mx += freq[i] * i;
        s -= freq[i];
    }

    cout << mx << ' ' << mn;
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
