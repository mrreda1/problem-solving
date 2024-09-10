#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#define max(x, y) ((x > y)?(x):(y))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    llu n, i, mx = 1;
    cin >> n;
    pair<llu, llu> time[n];
    priority_queue<llu, vector<llu>, greater<llu>> leave;
    for (i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
    }
    sort(time, time + n);
    for (i = 0; i < n; i++) {
        while (!leave.empty()) {
            if (time[i].first > leave.top()) {
                leave.pop();
            } else {
                break;
            }
        }
        leave.push(time[i].second);
        mx = max(mx, leave.size());
    }
    cout << mx;
}

void tsolve();
void io();

int main() {
	io();
	solve();
}
void tsolve() {
	int t;
	cin >> t;
	while (t--) {
		solve();
        cout << '\n';
	}
}
void io() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
