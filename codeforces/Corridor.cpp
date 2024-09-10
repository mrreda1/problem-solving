#include <iostream>

using namespace std;

void solve() {
    int n, d, s, i, min = 1e5, crnt;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> d >> s;
        crnt = d + (s - 1) / 2;
        if(min > crnt) min = crnt;
    }
    cout << min << endl;
}
int main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
