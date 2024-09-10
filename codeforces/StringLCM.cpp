#include <iostream>
#include <algorithm>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    string a, b, seq;
    cin >> a >> b;
    llu seqSize = __gcd(a.size(), b.size());
    seq = a.substr(0, seqSize);
    for (int i = 0; i < a.size(); i += seqSize) {
        if (seq.compare(a.substr(i, seqSize))) {
            cout << -1 << '\n';
            return;
        };
    }
    for (int i = 0; i < b.size(); i += seqSize) {
        if (seq.compare(b.substr(i, seqSize))) {
            cout << -1 << '\n';
            return;
        };
    }
    llu n = a.size()/seqSize * b.size()/seqSize;
    while (n--) {
        cout << seq;
    }
    cout << '\n';
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
