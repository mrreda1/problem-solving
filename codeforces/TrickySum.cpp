#include <cmath>
#include <iostream>

using namespace std;
long long solve() {
    long long n, result;
    cin >> n;
    result = (n*(n+1))/2 - 2*((1<<(((int)log2(n))+1))-1);
    return result;
}
int main () {
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
}
