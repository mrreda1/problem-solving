#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

int isPrime(long long n) {
    if (n < 2 || ((n%2==0)&&n!=2)) return 0;
    for(unsigned long i = 3; i*i <= n; i+=2)
        if (n%i == 0) return 0;
    return 1;
}
llu getNextPrime(llu n) {
    for (int i = n;; i++) {
        if (isPrime(i)) {
            return i;
        }
    }
}
void solve() {
    llu d, a;
    cin >> d;
    a = getNextPrime(1 + d);
    cout << a*getNextPrime(a + d) << '\n';
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
