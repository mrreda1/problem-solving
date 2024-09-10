#include <iostream>
#include <cmath>
#include <algorithm>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

void cng(llu *a, llu *b, llu x) {
    *b = x/(*a);
    *a = x/(*b);
}
void solve() {
    llu x, a, b = 1;
    cin >> x;

    a = sqrt(x);

    cng (&a, &b, x);
    while (a*b != x || a/(__gcd(a, b)) != x/b) {
        a--;
        cng(&a, &b, x);
    }
    cout << a << ' ' << b;
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
