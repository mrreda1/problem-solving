#include <iostream>

using namespace std;
void solve(int n) {
    int i, x, maxi, a[n*2+1];
    for (i = 1, maxi = 0; i <= n; i++) {
        cin >> x;
        while (maxi && x > a[maxi])
            maxi -= 2;
        cout << ((maxi)?(a[maxi-1]):(-1)) << ' ';
        a[++maxi] = i;
        a[++maxi] = x;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
}
