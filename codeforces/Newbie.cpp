#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    double n, k, a;
    cin >> n >> k >> a;
    double equ = ((-n + k) * (long long)pow(a, 4)) / (2.0 * (long long)pow(a, 3));
    if((float) equ > (long long) equ) { 
        cout << "double";
    }
    else if(equ < -2147483647.0 || equ > 2147483648.0) {
        cout << "long long";
    }
    else {
        cout << "int";
    }
}

int main () {
    solve();
}
