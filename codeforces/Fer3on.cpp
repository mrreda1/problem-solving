#include <iostream>

using namespace std;
void solve() {
	string x, y;
	char tmp;
	cin >> x >> y;
	size_t len = x.length();
	for (ssize_t i = len - 1; i >= 0; i -= 2) {
		tmp = x[i];
		x[i] = y[i];
		y[i] = tmp;
	}
	cout << x << '\n' << y << '\n';
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
