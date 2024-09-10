#include <iostream>
#include <vector>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    ll sum = 0, n;
    vector<ll> nums;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if ((a[0]/abs(a[0]))*a[1] < 0) {
        sum = a[0];
    } else {
        a[1] += a[0];
    }
    for (int i = 1; i < n; i++) {
        if ((a[i]/abs(a[i]))*a[i - 1] < 0) {
            nums.push_back(sum);
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    nums.push_back(sum);
    sum = 0;
    for (ll num: nums) {
        sum = abs(sum + num);
    }
    cout << sum << '\n';
}

void tsolve();
void io();

int main() {
	io();
	tsolve();
}
void tsolve() {
	int t;
	cin >> t;
	while (t--) {
		solve();
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
