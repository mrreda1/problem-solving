#include <iostream>

using namespace std;
string solve() {
    int *p1, *p2, s[4];
    p1 = s;
    p2 = s + 2;

    for(int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    if(p1[0]+p1[1] < p2[0]+p2[1]) {
        p1 = s + 2;
        p2 = s;
    }
    if(p1[0] > p2[0] && p1[0] > p2[1] &&
       p1[1] > p2[0] && p1[1] > p2[1])
        return "NO";
    return "YES";
}
int main () {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
}
