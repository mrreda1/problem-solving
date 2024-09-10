#include <iostream>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, i, x, cnt;
    cin >> n;
    int a[n+1];
    for (i = 1; i <= n; i++) {
        cin >> x;
        a[x] = i;
    }
    for (i = 2, cnt = 1; i <= n; i++) {
        if (a[i] < a[i-1]) cnt++;
    }
    cout << cnt;
}
