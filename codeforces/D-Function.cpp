#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;

ll fastPow(ll b, ll p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1)
            res = mul_mod(res, b, MOD);
        b = mul_mod(b, b, MOD);
        p >>= 1;
    }
    return res;
}

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;
    cout << sub_mod(fastPow(9/k + 1, r), fastPow(9/k + 1, l), MOD);
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
