#include <iostream>

using namespace std;
int main () {
    int k, s, groups = 0;
    cin >> k >> s;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int x = s - i - j;
            if (x >= 0 && x <= k) {
                groups++;
            }
        }
    }
    cout << groups;
}

