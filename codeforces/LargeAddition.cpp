#include <cmath>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll x, a, b;
    cin >> x;
    a = x / 2;
    b = x - a;
    if (int(log(a)/log(10)) != int(log(b)/log(10))) {
        cout << "NO\n";
        return;
    }
    for (int i = 0, rng = log(a)/log(10) + 1; i < rng; i++) {
        if ((a%10) + (b%10) < 10) {
            if (i == rng - 1 || (a%10) + (b%10) == 9) {
                cout << "NO\n";
                return;
            }
            a -= 10;
        }
        a /= 10;
        b /= 10;
    }
    cout << "YES\n";
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
