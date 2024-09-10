#include <bitset>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
long solve () {
    long x, y, maxseq = 0, lim, seq = 0;
    cin >> x >> y;
    lim = (log(min(x, y))/log(2)) + 1;
    x = x^y;
    bitset<64> dbit(x);
    string str = dbit.to_string();
    for (int i = 64; i > 64 - lim; i--) {
        if (str[i] == '0') {
            seq++;
        } else {
            maxseq = max(maxseq, seq);
            seq = 0;
        }
    }
    return (1 << max(maxseq, seq));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}
}
