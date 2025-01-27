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
    int n = nxt<int>(), id = 0;
    vector<vector<int>> population(n), subf;
    map<string, array<int, 2>> features;
    for (int i = 0; i < n; i++) {
        population[i].resize(nxt<int>());
        for (int j = 0; j < population[i].size(); j++) {
            string f = nxt<string>();
            if (!features.count(f)) {
                features[f][1] = id++;
                subf.push_back({});
            }
            population[i][j] = features[f][1];
            subf[features[f][1]].push_back(i);
            features[f][0]++;
        }
    }

    vector<bool> done(id, 0);
    vector<int> freq(id), prevalent(id);
    vector<array<int, 2>> tmp(id);
    for (auto [_, info] : features) {
        freq[info[1]] = info[0];
        tmp[info[1]] = info;
    }
    sort(all(tmp));
    for (int i = 0; i < id; i++) {
        prevalent[i] = tmp[i][1];
    }
    while (prevalent.size() && freq[prevalent.back()] > 1) {
        int p = prevalent.back();
        map<int, int> pfreq;
        for (int i : subf[p]) {
            for (int x : population[i]) {
                if (!done[x]) {
                    pfreq[x]++;
                }
            }
        }
        for (auto [x, f] : pfreq) {
            if (freq[x] != f) {
                cout << "no";
                return;
            }
        }
        done[p] = true;
        prevalent.pop_back();
    }
    cout << "yes";
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
