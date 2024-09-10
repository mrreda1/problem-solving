#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    string name[5] = {"", "Hussien", "Atef", "Karemo", "Ezzat"};
    int speed[5] = {0}, mx[2] = {0};
    for (int i = 1; i <= 4; i++) {
        cin >> speed[i];
    }

    for (int i = 1; i <= 4; i++) {
        if (speed[mx[0]] < speed[i]) {
            mx[1] = mx[0];
            mx[0] = i;
        } else if (speed[mx[1]] < speed[i]) {
            mx[1] = i;
        }
    }

    cout << name[mx[0]] << ' ' << name[mx[1]];
}

void tsolve();
void io();

int main() {
    io();
    tsolve();
}
void tsolve() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
void io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
