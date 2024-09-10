#include <iostream>

using namespace std;

int solve () {
    int n, i, mx, mn, x, mxi, mni;
    cin >> n;
    for (i = mx = 0, mn = 101; i < n; i++) {
        cin >> x;
        x *= 100;
        if (mx < x) {
            mx = x;
            mxi = i;
        }
        if (mn > x) {
            mn = x;
            mni = i;
        }
    }
    if (mxi < mni) {
        mxi += mni;
        mni = mxi - mni;
        mxi -= mni;
    }
    return min(min(n - mni, mxi + 1), n - mxi + mni + 1);
}
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
