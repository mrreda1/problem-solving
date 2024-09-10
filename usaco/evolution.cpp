#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "evolution";


void solve() {
    int n = nxt<int>();
    vector<set<set<string>>> cows(26);
    set<vector<string>> nodes;
    while (n--) {
        int k = nxt<int>();
        set<string> cow;
        while (k--)
            cow.insert(nxt<string>());
        cows[cow.size()].insert(cow);
    }
    for (int i = 1; i < 26; i++) {
        vector<string> powers;
        map<string, int> freq;
        while (cows.begin()->begin()->size() > 1) {
            vector<string> node;
            for (auto cow : cows[i]) {
            }
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
