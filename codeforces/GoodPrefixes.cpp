#include <algorithm>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, i, cnt = 0, mx = -1;
    cin >> n;
    ll a[n + 1] = {0}, prfx[n + 1] = {0};
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        prfx[i] = a[i] + prfx[i - 1];
    }
    for (i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        if (2*mx == prfx[i]) {
            cnt++;
        }
    }
    cout << cnt;
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
