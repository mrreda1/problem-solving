#include <iostream>
using namespace std;
int dev(long long a, long long b, long long x)
{
    long long max = 0, min = 0;
    int modMax = 0, modMin = 0;
    long long result = 0;
    if (a > b) {
        max = a, min = b;
    } else {
        max = b, min = a;
    }

    if (x < min) {
        modMin = min % x; // x =4 min=5 mod = 1
        if (modMin == 0)
            modMin = x;
        min = min + (x - modMin); // min= 8
    } else {
        min = x;
    }

    if (max % x != 0) {
        modMax = max % x;   // x=4 max=39 mod=3
        max = max - modMax; // max=39-3=36
    }

    result = ((max - min) / x) + 1;
    return result;
}
int main()
{
    long long a, b, x;
    cin >> a >> b >> x;
    if (a == b && a % x == 0) {
        cout << 1;
        return 0;
    }
    long long res = dev(a, b, x);
    cout << res;
}
