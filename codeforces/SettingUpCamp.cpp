#include <iostream>

using namespace std;

int solve() {
	int a, b, c, t;
	cin >> a >> b >> c;
	t = a;
	t += (b + 2) / 3;
	c -= 3 - ((b % 3) ? (b % 3) : 3);
    if (c < 0) {
        return -1;
    }
    t += (c + 2) / 3;
    return t;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << endl;
	}
}
