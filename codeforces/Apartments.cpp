#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    int n, m, k, i, j, cnt;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    for (cnt = i = j = 0; i < n && j < m;) {
        if (b[j] < a[i] - k) {
            j++;
        } else if (b[j] > a[i] + k) {
            i++;
        } else cnt++, i++, j++;
    }
    cout << cnt;
}
