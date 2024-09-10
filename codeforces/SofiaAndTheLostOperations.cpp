#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
bool solve () {
    map<long, unsigned> freq;
    int n, m, i, cnt = 1;
    bool endchk = false;

    cin >> n;
    long a[n], b[n];

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }

    cin >> m;
    long d[m];

    for (i = 0; i < m; i++) {
        cin >> d[i];
    }
    for (i = 0; i < n; i++) {
        if (d[m - 1] == b[i]) {
            endchk = true;
            break;
        }
    }
    if (!endchk) {
        return 0;
    }
    sort(d, d + m);

    for (i = 0; i < m - 1; i++) {
        if (d[i] == d[i + 1]) {
            cnt++;
        } else {
            freq[d[i]] = cnt;
            cnt = 1;
        }
    }
    freq[d[i]] = cnt;

    for (i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            if (freq.find(b[i]) == freq.end() || freq[b[i]] <= 0) {
                return 0;
            }
            freq[b[i]]--;
        }
    }
    return 1;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve()?("YES"):("NO")) << '\n';
    }
}
