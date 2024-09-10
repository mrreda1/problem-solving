#include <cmath>
#include <iostream>

using namespace std;
int solve() {
    int n, x, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    if (sum == n) {
        return 0;
    } else if(sum < n) {
        return 1;
    }
    return sum - n;
}
int main () {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
}
