#include <bitset>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll n, i, num = 0, a, y, x = 0;
    cin >> n >> y;
    
    for (i = 0; i < n; i++) {
        cin >> a;
        num |= a;
    }

    bitset<64> numb = num, yb = y;

    for (i = 0; i < 64; i++) {
        if (numb[i] != yb[i]) {
            if (numb[i] == 1) {
                cout << -1;
                return;
            } else {
                x += 1LL << i;
            }
        }
    }
    cout << x;
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
