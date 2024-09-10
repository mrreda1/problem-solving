#include <iomanip>
#include <iostream>
#include <map>

using namespace std;
double solve() {
	map<string, double> coins;
	string coin;
	double currency = 0, x;
	long c, n, i;

	coins["JD"] = 1;
	cin >> c >> n;

	for (i = 0; i < c; i++) {
		cin >> coin >> x;
		coins[coin] = x;
	}
	for (i = 0; i < n; i++) {
		cin >> x >> coin;
		currency += coins[coin] * x;
	}
	return currency;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << fixed << setprecision(6) << solve() << '\n';
	}
}
