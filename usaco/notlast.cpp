#include <bits/stdc++.h>
#include <pthread.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define count_val(x, v)                                                        \
    count_if(all(x), [&](const auto &p) { return p.second == v; })

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "notlast";


void solve() {
    int n = nxt<int>();
    map<string, int> cows{{"Bessie", 0},   {"Elsie", 0},     {"Daisy", 0},
                          {"Gertie", 0},   {"Annabelle", 0}, {"Maggie", 0},
                          {"Henrietta", 0}};
    while (n--) {
        string cow = nxt<string>();
        cows[cow] += nxt<int>();
    }
    vector<int> milk;
    for (auto [_, m] : cows) {
        milk.push_back(m);
    }
    make_unique(milk);
    if (milk.size() == 1) {
        cout << "Tie";
        return;
    }
    if (count_val(cows, milk[1]) > 1) {
        cout << "Tie";
        return;
    }
    for (auto cow : cows) {
        if (cow.second == milk[1]) {
            cout << cow.first;
            return;
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
