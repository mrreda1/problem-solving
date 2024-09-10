#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll freq[128] = {0}, n, i, r = 0;
    string s;

    cin >> n >> s;
    
    for (i = 1; i < n; i++) {
        freq[s[i]]++;
    }

    for (i = 0; i < 128; i++) {
        r += (freq[i] * (freq[i] + 1)) / 2;
    }
    cout << r;
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
