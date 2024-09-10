#include <iostream>
#include <algorithm>

using namespace std;
int solve () {
    int n, i;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
