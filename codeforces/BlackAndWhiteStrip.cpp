#include <iostream>

using namespace std;

long solve() {
    long x, y, e, min = 0, crnt;
    string str;
    cin >> x >> y >> str;

    for (int i = 0; i < y; i++)
        if (str[i] == 'W') min++;

    for (crnt = min, e = y; e < x; e++) {
        if (str[e-y] == 'W') crnt--;
        if (str[e] == 'W') crnt++;
        if (min > crnt) min = crnt;
    }
    return min;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
