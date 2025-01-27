#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "lineup";


void solve() {
    int n = nxt<int>();
    map<string, int> id;
    array<vector<int>, 8> edges;
    vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                            "Bella",  "Blue",      "Betsy",   "Sue"};
    sort(all(names));

    for (int i = 0; i < 8; i++) {
        id[names[i]] = i;
    }
    while (n--) {
        string c[2]{nxt<string>()};
        for (int i = 0; i < 5; i++) {
            c[1] = nxt<string>();
        }
        edges[id[c[0]]].push_back(id[c[1]]);
        edges[id[c[1]]].push_back(id[c[0]]);
    }
    array<bool, 8> milked{};
    for (int i = 0; i < 8; i++) {
        if (!edges[i].size()) {
            cout << names[i] << endl;
        } else if (edges[i].size() == 1 && !milked[i]) {
            int crnt = edges[i][0], parent = i;
            cout << names[i] << endl;
            do {
                cout << names[crnt] << endl;
                if (edges[crnt].size() == 1) {
                    milked[crnt] = true;
                } else {
                    int tmp = crnt;
                    crnt = edges[crnt][edges[crnt][0] == parent];
                    parent = tmp;
                }
            } while (!milked[crnt]);
        }
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
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
