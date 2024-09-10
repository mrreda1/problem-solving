#include <algorithm>
#include <iostream>

using namespace std;
using llu = unsigned long long;

void solve() {
	int freq[2][128] = {{0}, {0}}, cnt = 0;
	string a, b;
	cin >> a >> b;
	for (char c : a) {
		freq[0][c]++;
	}
	for (char c : b) {
		freq[1][c]++;
	}
	for (int i = 0; i < 128; i++) {
		if (freq[1][i] && !freq[0][i]) {
			cout << -1;
			return;
		}
		cnt += min(freq[0][i], freq[1][i]);
	}
	cout << cnt;
}
void io();
int main() {
	io();
	solve();
}
void io() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
