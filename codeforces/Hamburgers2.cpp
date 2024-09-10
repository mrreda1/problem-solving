#include <climits>
#include <iostream>

using namespace std;
using llu = unsigned long long;
using ll = long long;

bool check(ll *n, ll *p, ll *freq, ll s, ll e, ll money) {
	ll numOfHams = (s + e) / 2;
	for (int i = 0; i < 3; i++) {
		if (n[i] < freq[i] * numOfHams) {
			money -= (freq[i] * numOfHams - n[i]) * p[i];
		}
	}
	if (money < 0)
		return false;
	return true;
}
void solve() {
	string ham;
	ll n[3], p[3], money, freq[3] = {0};
	ll s = 0, e = 1e14, numOfHams;

	cin >> ham;
	cin >> n[0] >> n[1] >> n[2];
	cin >> p[0] >> p[1] >> p[2];
	cin >> money;

	for (char c : ham) {
		freq[(c == 'B') ? (0) : ((c == 'S') ? (1) : (2))]++;
	}

	while (true) {
		numOfHams = (s + e) / 2;
		if (!check(n, p, freq, s, e, money)) {
			e = numOfHams;
		} else if (check(n, p, freq, s + 1, e, money)) {
			s = numOfHams;
		} else {
			cout << numOfHams << '\n';
			return;
		}
	}
}
void io();
int main() {
	io();
	solve();
}
void io() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
