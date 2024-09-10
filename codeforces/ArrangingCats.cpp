#include <iostream>

using namespace std;

int solve() {
    int l, x[2] = {0, 0};
    cin >> l;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < l; i++) {
        if (s1[i] != s2[i])
            x[s1[i] - '0']++;
    }
    return (x[0] > x[1])?(x[0]):(x[1]);
}

int main () {
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
}
