#include <cmath>
#include <iostream>
#include <algorithm>
#include <utility>

typedef unsigned long long llu;
using namespace std;
void solve() {
	llu w, n, m, total = 0;
	cin >> n >> w;
	pair<llu, llu> x[n];
    bool skip[n + 1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> x[i].first;
        total += x[i].first;
        x[i].second = i + 1;
	}
	sort(x, x + n);
    if (total < ceil(w/2.0) || x[0].first > w) {
        cout << -1 << '\n';
        return;
    }

    m = n;
    for (int i = n - 1; i >= 0; i--) {
        if (total >= ceil(w/2.0) && total <= w) {
            cout << m << '\n';
            for (i = 1; i <= n; i++) {
                if (!skip[i]) {
                    cout << i << ' ';
                }
            }
            cout << '\n';
            return;
        }
        if (total - x[i].first >= ceil(w/2.0)) {
            total -= x[i].first;
            skip[x[i].second] = true;
            m--;
        }
    }
    if (total >= ceil(w/2.0) && total <= w) {
        cout << m << '\n';
        for (int i = 1; i <= n; i++) {
            if (!skip[i]) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
