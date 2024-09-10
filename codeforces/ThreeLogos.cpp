#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    char company[3]{'A', 'B', 'C'};
    int sum = 0, mx = 0;
    vector<vector<int>> logos(3, vector<int>(2));
    for (int i = 0; i < 3; i++) {
        cin >> logos[i][0] >> logos[i][1];
        sum += logos[i][0] * logos[i][1];
        sort(all(logos[i]));
        if (logos[i][1] > logos[mx][1]) {
            mx = i;
        }
    }
    vector<int> l = logos[(mx + 1) % 3], r = logos[(mx + 2) % 3];
    if (static_cast<int>(sqrt(sum)) * static_cast<int>(sqrt(sum)) != sum ||
        logos[mx][1] != sqrt(sum)) {
        cout << -1;
        return;
    }
    if (l[1] == r[1] && l[1] == logos[mx][1]) {
        cout << l[1] << endl;
        for (int x = 0; x < 3; x++) {
            for (int i = 0; i < logos[x][0]; i++) {
                for (int j = 0; j < l[1]; j++) {
                    cout << company[x];
                }
                cout << endl;
            }
        }
        return;
    }
    bool done = false;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (l[i] == r[j] && l[i] == logos[mx][1] - logos[mx][0]) {
                l.erase(l.begin() + i);
                r.erase(r.begin() + j);
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    if (l.size() == 2) {
        cout << -1;
        return;
    }
    cout << logos[mx][1] << endl;
    for (int i = 0; i < logos[mx][0]; i++) {
        for (int j = 0; j < logos[mx][1]; j++) {
            cout << company[mx];
        }
        cout << endl;
    }
    for (int i = 0; i < logos[mx][1] - logos[mx][0]; i++) {
        for (int j = 0; j < l[0]; j++) {
            cout << company[(mx + 1) % 3];
        }
        for (int j = 0; j < r[0]; j++) {
            cout << company[(mx + 2) % 3];
        }
        cout << endl;
    }
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
