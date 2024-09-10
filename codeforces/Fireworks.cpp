#include <iostream>

using namespace std;
long long solve() {
    long long a, b, m;
    cin >> a >> b >> m;
    return (m/a+m/b)+2;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
}
