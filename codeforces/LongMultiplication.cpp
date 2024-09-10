#include <iostream>

using namespace std;
void solve () {
    char x[102], y[102], tmp;
    cin >> x >> y;
    int i;

    for (i = 0; x[i]; i++) {
        if (x[i] < y[i]) {
            tmp = x[i];
            x[i] = y[i];
            y[i] = tmp;
        }
        if (x[i] > y[i]) {
            i++;
            break;
        }
    }
    for (; x[i]; i++) {
        if (x[i] > y[i]) {
            tmp = x[i];
            x[i] = y[i];
            y[i] = tmp;
        }
    }
    cout << x << '\n' << y << '\n';
}
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
