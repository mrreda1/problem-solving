#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "backforth";

void solve() {
    int gallons = 0;
    set<int> res;
    vector<vector<int>> barns(2, vector<int>(10));

    for (int i = 0; i < 10; i++) {
        cin >> barns[0][i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> barns[1][i];
    }

    function<void(int)> move = [&](int day) {
        if (day == 4) {
            res.insert(gallons);
        } else {
            for (int i = 0; i < barns[day & 1].size(); i++) {
                gallons += barns[day & 1][i] * ((day & 1) ? (1) : (-1));
                barns[!(day & 1)].push_back(barns[day & 1][i]);
                barns[day & 1].erase(barns[day & 1].begin() + i);
                move(day + 1);
                barns[day & 1].insert(barns[day & 1].begin() + i,
                                      barns[!(day & 1)].back());
                barns[!(day & 1)].pop_back();
                gallons -= barns[day & 1][i] * ((day & 1) ? (1) : (-1));
            }
        }
    };

    move(0);
    cout << res.size();
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
