#include <iostream>

using namespace std;
int main () {
    int n, f[3] = {0}, x, crnt = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        f[x]++;
    }
    for (x = 2; f[1] || f[2]; x++) {
        bool prime = 1;
        for (n = 2; n*n <= x; n++) {
            if (!(x%n)) {
                prime = 0;
                break;
            }
        }
        if (prime) {
            while (crnt < x) {
                if (x - crnt >= 2 && f[2]) {
                    f[2]--;
                    crnt += 2;
                    cout << 2 << ' ';
                } else if (f[1]) {
                    f[1]--;
                    crnt += 1;
                    cout << 1 << ' ';
                } else if (f[2]){
                    while (f[2]--) {
                        cout << 2 << ' ';
                    }
                    f[2]++;
                } else {
                    return 0;
                }
            }
        }
    }
}
