#include <iostream>

using namespace std;
int solve () {
    int prbf[7] = {0}, n, m, cnt = 0;
    string prbs;

    cin >> n >> m >> prbs;
    for (char c: prbs) {
        prbf[c - 'A']++;
    }

    for (int prb: prbf) {
        cnt += (prb < m)?(m - prb):(0);
    }
    return cnt;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve () << '\n';
    }
}
