#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "badmilk";

void solve() {
    int N, M, D, S, x, y, z, mx = 0;
    cin >> N >> M >> D >> S;
    int sick[N + 1][M + 1]{};

    while (D--) {
        cin >> x >> y >> z;
        if (sick[x][y]) {
            sick[x][y] = min(sick[x][y], z);
        } else {
            sick[x][y] = z;
        }
    }
    while (S--) {
        cin >> x >> y;
        for (int i = 1; i <= M; i++) {
            if (sick[x][i] >= y) {
                for (int j = 1; j <= N; j++) {
                    sick[j][i] = 0;
                }
            }
        }
    }
    for (int m = 1; m <= M; m++) {
        int cnt = 0;
        for (int p = 1; p <= N; p++) {
            if (sick[p][m]) cnt++;
        }
        mx = max(cnt, mx);
    }
    cout << mx;
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
