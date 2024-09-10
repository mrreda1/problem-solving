#include <iostream>
#define f_ev(x) ((x % 2)?(x + 1):(x))

using namespace std;

void solve() {
    int l, r, a, b;
    cin >> l >> r;
    if(l < 3 && r < 4) {
        cout << -1 << endl;
        return;
    }
    if(r > l || l % 2 == 0) {
        cout << ((f_ev(l) - 2)?(f_ev(l) - 2):(2)) << ' ' << 2 << endl;
        return;
    }
    for(int i = 3; i*i <= l; i++) {
        if(((l - i)/ i != 1) && ((float)(l - i) / i) == (l - i) / i) {
            cout << i << ' ' << l - i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        solve();
}
