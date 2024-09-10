#include <iostream>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    int t;
    cin >> t;
    int s = -2*1e9, e = 2*1e9, v;
    string q, a;
    while (t--) {
        cin >> q >> v >> a;
        if (a.compare("Y")) {
            if (q[0] == '>') {
                e = min(v - ((q[1])?(1):(0)), e);
            } else {
                s = max(v + ((q[1])?(1):(0)), s);
            }
        } else {
            if (q[0] == '>') {
                s = max(v + ((q[1])?(0):(1)), s);
            } else {
                e = min(v - ((q[1])?(0):(1)), e);
            }
        }
    }
    if (s > e) {
        cout << "Impossible";
    } else {
        cout << s;
    }
}

void tsolve();
void io();

int main() {
    io();
    solve();
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
