#include <iostream>

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

void solve(){
	long long x, y, k;
	cin >> x >> y >> k;
	while (k > 0 && x != 1) {
		long long ost = (x / y + 1) * y - x;
                ost = max(1ll, ost);
                ost = min(ost, k);
                x += ost;
		while (x % y == 0) {
			x /= y;
		}
		k -= ost;
	}
	cout << x + k % (y - 1);
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
