#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    int n = nxt<int>();
    array<string, 8> info;
    map<string, int> mounth;
    map<string, int> bd;
    map<string, int> year{{"Bessie", 0}};
    vector<string> m{"Ox",   "Tiger",  "Rabbit",  "Dragon", "Snake", "Horse",
                     "Goat", "Monkey", "Rooster", "Dog",    "Pig",   "Rat"};
    for (int i = 0; i < 12; i++) {
        mounth[m[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        generate(all(info), nxt<string>);
        bd[info[0]] = mounth[info[4]];
        if (info[3] == "next") {
            int diff = bd[info[0]] - bd[info[7]];
            year[info[0]] = year[info[7]] + ((diff) ? (diff + 12) % 12 : 12);
        } else {
            int diff = bd[info[7]] - bd[info[0]];
            year[info[0]] = year[info[7]] - ((diff) ? (diff + 12) % 12 : 12);
        }
    }
    cout << abs(year["Elsie"]);
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
