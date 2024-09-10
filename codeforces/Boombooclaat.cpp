#include <iostream>

using namespace std;
string solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        return "WeWillEatYou";
    } else {
        return "FunkyMonkeys";
    }
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
