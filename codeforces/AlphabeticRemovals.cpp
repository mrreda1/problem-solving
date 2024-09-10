#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0)?(-(x)):((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
    string word;
    int k, n, skip[256] = {0};

    cin >> n >> k;
    cin >> word;

    for (int i = 0; i < n; i++) {
        skip[word[i]]++;
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (k > skip[i]) {
            k -= skip[i];
        } else {
            skip[i] = k;
            k = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (skip[word[i]]) {
            --skip[word[i]];
        } else {
            cout << word[i];
        }
    }
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
