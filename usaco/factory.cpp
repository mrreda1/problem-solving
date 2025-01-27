#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "factory";


void BetterSolution() {
    vector<bool> valid(nxt<int>(), 1);
    for (int i = 1; i < valid.size(); i++) {
        int x = nxt<int>();
        valid[x - 1] = !nxt<int>();
    }
    cout << (count(all(valid), 1) == 1 ? find(all(valid), 1) - valid.begin() + 1 : -1);
}
void DFSSolution() {
    int n = nxt<int>(), x, y;
    bool dp[n]{};
    vector<int> walkways[n];
    set<int> paths[n];
    for (int i = 1; i < n; i++) {
        x = nxt<int>(), y = nxt<int>();
        walkways[y - 1].push_back(x - 1);
    }
    function<void(int)> findPaths = [&](int i) {
        if (dp[i]) return;
        for (int station : walkways[i]) {
            paths[i].insert(station);
            if (!dp[station]) findPaths(station);
            paths[i].insert(all(paths[station]));
        }
        dp[i] = true;
    };
    for (int i = 0; i < n; i++) {
        findPaths(i);
        if (paths[i].size() == n - 1) {
            cout << i + 1;
            return;
        }
    }
    cout << -1;
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
            NormalSolution();
            cout << '\n';
        }
    } else {
        NormalSolution();
    }
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
