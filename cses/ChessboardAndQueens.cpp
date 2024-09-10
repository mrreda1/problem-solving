#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    vector<array<int, 2>> queen;
    char chess[8][8];
    int res = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    function<void(int)> checkMate = [&](int x) {
        if (x == 8) {
            res++;
            return;
        }
        for (int i = 0; i < 8; i++) {
            bool ok = true;
            if (chess[x][i] == '*') {
                continue;
            }
            for (array<int, 2> q : queen) {
                if (i == q[1] || abs(i - q[1]) == abs(x - q[0])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                queen.push_back({x, i});
                checkMate(x + 1);
                queen.pop_back();
            }
        }
    };
    checkMate(0);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (iofile != "") {
        freopen((iofile + ".in").c_str(), "r", stdin);
        freopen((iofile + ".out").c_str(), "w", stdout);
    }
#endif
    if (T) {
        int t;
        cin >> t;
        while (t--) {
            solve();
            cout << '\n';
        }
    } else {
        solve();
    }
}
