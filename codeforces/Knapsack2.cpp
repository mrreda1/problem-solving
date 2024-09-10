#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using llu = unsigned long long;
using namespace std;
void solve() {
	llu w, n, sum = 0, x;
	cin >> n >> w;
	vector<pair<llu, llu>> vec;
	vector<llu> result;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x <= w) {
			vec.push_back({x, i});
			sum += x;
		}
	}
	if (sum < ceil(w / 2.0)) {
		cout << -1 << '\n';
		return;
	}
	sort(vec.rbegin(), vec.rend());
	sum = 0;
	for (auto num : vec) {
		result.push_back(num.second);
		sum += num.first;
		if (sum >= ceil(w / 2.0)) {
			break;
		}
	}
	cout << result.size() << '\n';
	for (auto num : result) {
		cout << num << ' ';
	}
	cout << '\n';
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
