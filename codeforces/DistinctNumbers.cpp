#include <iostream>
#include <algorithm>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, cnt, i=0;
    cin >> n;
    unsigned long a[n];
    while (i < n)
        cin >> a[i++];
    sort(a, a + n);
    for (cnt = i = 1; i < n; i++)
        (a[i]==a[i-1])?:(cnt++);
    cout << cnt;
}
