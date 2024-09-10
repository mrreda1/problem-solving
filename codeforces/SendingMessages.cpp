#include <iostream>
#define min(x, y) ((x < y)?(x):(Y))

using namespace std;

string solve() {
    long long n, f, a, b, mmnt = 0, msg, diff;
    cin >> n >> f >> a >> b;

    while(n--) {
        cin >> msg;
        diff = (msg - mmnt)*a;
        f -= (diff < b)?(diff):(b);
        mmnt = msg;
    }

    return (f > 0)?("YES"):("NO");
}

int main () {
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
}
