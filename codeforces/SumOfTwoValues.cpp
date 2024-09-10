#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, x, i, t, l, r, m;
    cin >> n >> x;
    pair<int, int> a[n];
    for (i = 0; i < n; i++) {
        cin >> t;
        a[i] = {t, i+1};
    }
    sort(a, a+n);
    r = n - 1;
    for (i = 0; i < n - 1; i++) {
        l = i + 1;
        while (l <= r) {
            m = (r + l) / 2;
            if (a[m].first == x - a[i].first) {
                cout << a[i].second << ' ' << a[m].second;
                return 0;
            } else if (a[m].first < x - a[i].first) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
