#include <iostream>

using namespace std;

int solve() {
    int axis[4][2], sqr = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0;j < 2; j++)
            cin >> axis[i][j];
    }
    for (int i = 1; i < 4; i++) {
        if (axis[i][0] == axis[0][0]) {
            sqr = (axis[i][1] - axis[0][1]);
            break;
        }
    }
    return sqr*sqr;
}

int main () {
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
}
