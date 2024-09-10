#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;
void solve() {
    double n;
    cin >> n;
    if (n < 4 && n != 0) {
        cout << 'N' << '\n';
    } else {
        double x = (n + sqrt(n*(n - 4)))/2;
        cout << "Y " << fixed << setprecision(9) << x << ' ' << n - x << '\n';
    }
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
