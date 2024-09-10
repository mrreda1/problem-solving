#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool ok = true;
	int n, q, s, i = 0, qt, *r, ri;
	cin >> n >> q;
	int a[n + 1] = {0};
	s = n + 1;
	while (i++ < n) {
		cin >> a[i];
		if (a[i] < a[i - 1] && ok)
			s = i, ok = false;
	}
	if (s < n + 1)
		sort(a + s, a + n + 1);
	while (q--) {
		cin >> qt;
		r = upper_bound(a, a + s, qt) - 1;
		if (*r == qt) {
			ri = r - a;
			if (ri >= s)
				ri = n - ri + s;
			cout << "Yes " << ri << '\n';
			continue;
		} else if (s != n + 1) {
			r = upper_bound(a + s, a + n + 1, qt) - 1;
			if (*r == qt) {
				ri = r - a;
				if (ri >= s)
					ri = n - ri + s;
				cout << "Yes " << ri << '\n';
				continue;
			}
		}
		cout << "No\n";
	}
}
