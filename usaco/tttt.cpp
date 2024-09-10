#include <bits/stdc++.h>
#include <set>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;


const bool T = 0;
const string iofile = "tttt";

void checkWinner(set<set<char>> &single, set<set<char>> &teams,
                 set<char> &win) {
    if (win.size() == 1) {
        single.insert(win);
    } else if (win.size() == 2) {
        teams.insert(win);
    }
    win.clear();
}
void solve() {
    set<set<char>> single, teams;
    set<char> win;
    char ttt[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> ttt[i][j];
        }
    }

    // Rows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            win.insert(ttt[i][j]);
        }
        checkWinner(single, teams, win);
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            win.insert(ttt[j][i]);
        }
        checkWinner(single, teams, win);
    }

    // First diagonal
    for (int i = 0; i < 3; i++) {
        win.insert(ttt[i][i]);
    }
    checkWinner(single, teams, win);

    // Second diagonal
    for (int i = 0; i < 3; i++) {
        win.insert(ttt[i][2 - i]);
    }
    checkWinner(single, teams, win);

    cout << single.size() << endl << teams.size();
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
