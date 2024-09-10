#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
long solve () {
    long n, m = LONG_MAX;
    cin >> n;
    long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        m = min(m, max(arr[i], arr[i-1])); 
    }
    return m - 1;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
