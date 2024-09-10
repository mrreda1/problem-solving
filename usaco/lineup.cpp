#include <algorithm>
#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "lineup";

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> constraints(n);
    string permutation = "01234567";
    map<string, int> cows;
    vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                            "Bella",  "Blue",      "Betsy",   "Sue"};
    sort(all(names));

    for (int i = 0; i < 8; i++) {
        cows[names[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        constraints[i][0] = cows[name];
        for (int j = 0; j < 5; j++) {
            cin >> name;
        }
        constraints[i][1] = cows[name];
    }

    do {
        bool done = true;
        for (int c = 0; c < n; c++) {
            bool valid = false;
            for (int i = 0; i < 8; i++) {
                if (constraints[c][0] == permutation[i] - '0') {
                    if ((i != 0 && permutation[i - 1] - '0' == constraints[c][1]) ||
                        (i != 7 && permutation[i + 1] - '0' == constraints[c][1])) {
                        valid = true;
                    }
                    break;
                }
            }
            if (!valid) {
                done = false;
                break;
            }
        }
        if (done) {
            for (char c : permutation) {
                cout << names[c - '0'] << endl;
            }
            return;
        }
    } while (next_permutation(all(permutation)));
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
