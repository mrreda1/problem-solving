#include <iostream>

using namespace std;
int main () {
    long long n, m, stps = -1, i, j;
    cin >> n >> m;
    char dir[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> dir[i][j];
        }
    }
    i = j = 0;
    while (stps++ <= 1e7) {
        switch (dir[i][j]) {
            case 'N':
                i--;
                break;
            case 'S':
                i++;
                break;
            case 'E':
                j++;
                break;
            case 'W':
                j--;
                break;
            default:
                cout << stps;
                return 0;
        }
        if ((i | j) < 0 || i >= n || j >= m) {
            cout << "out";
            return 0;
        }
    }
    cout << "lost";
}
