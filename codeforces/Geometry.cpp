#include <cmath>
#include <iomanip>
#include <iostream>
#define PI 3.1415926
#define SIN(x) sin((x) * PI / 180)

using namespace std;
double solve() {
	double l, a;
	cin >> l >> a;
	return (1.0 / 2 * l * l * sin(a * PI / 180.0));
}
int main(int argc, char *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cout << fixed << setprecision(6) << solve() << '\n';
	}
}
