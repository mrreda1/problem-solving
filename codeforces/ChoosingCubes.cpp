#include <iostream>
#include <algorithm>

using namespace std;
string solve () {
    int f, k, n, low, high;
    cin >> n >> f >> k;
    int cube[n];
    for (int i = 0; i < n; i++) {
        cin >> cube[i];
    }
    f = cube[f-1];
    sort(cube, cube + n);
    high = n - (lower_bound(cube, cube + n, f) - cube);
    low = n - (upper_bound(cube, cube + n, f) - cube) + 1;
    if (high <= k) {
        return "YES";
    } else if (low > k) {
        return "NO";
    } else {
        return "MAYBE";
    }
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
