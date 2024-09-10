#include <algorithm>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, k, l, r, i, sm, mx, crnt;
    cin >> n >> k;

    ll hour[n + 2] = {0};
    while (k--) {
        cin >> l >> r;
        hour[l] += 1;
        hour[r + 1] -=1;
    }
    for (i = 1, sm = mx = crnt = 0; i <= n; i++) {
        hour[i] += sm;
        sm = hour[i];
        if (sm == 0) {
            crnt++;
        } else {
            mx = max(mx, crnt);
            crnt = 0;
        }
    }
    cout << max(mx, crnt);
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
