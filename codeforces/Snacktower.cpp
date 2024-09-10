#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>

typedef unsigned long long llu;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
    priority_queue<pair<llu, unsigned>> tmp;
	llu snacks[n][2];
	llu ssnacks[n];

	for (int i = 0; i < n; i++) {
		cin >> snacks[i][0];
		ssnacks[i] = snacks[i][0];
	}

	sort(ssnacks, ssnacks + n);
	for (int i = 0; i < n; i++) {
		snacks[i][1] =
			n - (lower_bound(ssnacks, ssnacks + n, snacks[i][0]) - ssnacks) - 1;
	}

    for (int i = 0, cnt = 0; i < n; i++) {
        if (snacks[i][1] == cnt) {
            cnt++;
            cout << snacks[i][0] << ' ';
            while (!tmp.empty()) {
                if (tmp.top().second == cnt) {
                    cout << tmp.top().first << ' ';
                    cnt++;
                    tmp.pop();
                } else {
                    break;
                }
            }
        } else {
            tmp.push({snacks[i][0], snacks[i][1]});
        }
        cout << '\n';
    }
}
