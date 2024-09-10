#include <cmath>
#include <iostream>
#define abs(x) ((x < 0)?(-x):(x))

using namespace std;

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    int result = ceil(abs((a - b)/(c * 2)));
    cout << result << endl;
}
int main () {
    int t;
    cin >> t;
    while(t--)
        solve();
}
