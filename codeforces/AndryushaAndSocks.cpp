#include <algorithm>
#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    bool freq[int(1e5 + 1)] = {0};
    llu n, x, mx = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> x;
        if (freq[x]) {
            sum--;
            freq[x] = false;
        } else { 
            sum++;
            freq[x] = true;
        }
        mx = max(mx, sum);
    }
    cout << mx;
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
