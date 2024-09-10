#include <iostream>

using namespace std;
using llu = unsigned long long;

void solve() {
    int freq[int(2e5) + 1] = {0}, n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        freq[x]++;
        switch (freq[x]) {
            case 3:
                cout << x << '\n';
                while (n--)
                    cin >> x;
                return;
        }
    }
    cout << -1 << '\n';
}
void io();
int main() {
	io();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
void io() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
