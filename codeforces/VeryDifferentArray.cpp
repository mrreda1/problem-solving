#include <iostream>
#include <algorithm>

using namespace std;

int solve() {
    long long i, p1, p2, n , m, sum1 = 0, diff1, diff2;
    cin >> n >> m;

    long long a1[n], a2[m];

    for (i = 0; i < n; i++)
        cin >> a1[i];
    for (i = 0; i < m; i++)
        cin >> a2[i];

    sort(a1, a1 + n);
    sort(a2, a2 + m);

    for (p1=i=0, p2 = m - 1; 2*i < n-1; i++ ) {
        diff1 = abs(a1[i] - a2[p1]);
        diff2 = abs(a1[i] - a2[p2]);
        if (diff1 > diff2) {
            sum1 += diff1;
            p1++;
        } else {
            sum1 += diff2;
            p2--;
        }
        diff1 = abs(a1[n-i-1] - a2[p1]);
        diff2 = abs(a1[n-i-1] - a2[p2]);
        if (diff1 > diff2) {
            sum1 += diff1;
            p1++;
        } else {
            sum1 += diff2;
            p2--;
        }
    }
    if (2*i == n-1) {
        diff1 = abs(a1[i] - a2[p1]);
        diff2 = abs(a1[i] - a2[p2]);
        if (diff1 > diff2) {
            sum1 += diff1;
            p1++;
        } else {
            sum1 += diff2;
            p2--;
        }
    }
    return sum1;
}
int main () {
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
}
