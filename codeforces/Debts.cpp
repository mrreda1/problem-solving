#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll m, n, x, y, z;
    
    cin >> n >> m;
    ll a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (m--) {
        cin >> y >> x >> z;
        a[y] -= z;
        a[x] += z;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
