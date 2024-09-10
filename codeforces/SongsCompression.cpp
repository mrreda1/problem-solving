#include <iostream>
#include <algorithm>

using namespace std;
int main () {
    long long n, m, i, sngcnt = 0;
    cin >> n >> m;
    long long cmpdiff[n], sng, sngcmp;
    for (i = 0; i < n; i++) {
        cin >> sng >> sngcmp;
        sngcnt += sng;
        cmpdiff[i] = sng - sngcmp;
    }
    if (sngcnt <= m) {
        cout << 0;
        return 0;
    }
    sort(cmpdiff, cmpdiff + n);
    for (i = n - 1; i >= 0; i--) {
        sngcnt -= cmpdiff[i];
        if (sngcnt <= m) {
            cout << n - i;
            return 0;
        }
    }
    cout << -1;
}
