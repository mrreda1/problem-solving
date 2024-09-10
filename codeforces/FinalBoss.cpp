#include <iostream>
#include <vector>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll h, n, i, x;
    cin >> h >> n;
    vector<vector<ll>> a(n);
    for (i = 0; i < n; i++) {
        cin >> x;
        a[i].push_back(x);
    }
    for (i = 0; i < n; i++) {
        cin >> x;
        a[i].push_back(x);
    }
    sort (
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
